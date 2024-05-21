import influxdb_client, os, time, serial
from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS

# Configura il client InfluxDB
token = os.environ.get("INFLUXDB_TOKEN")
org = "andreinadatti"
url = "http://localhost:8086"
bucket = "arduino"

# Crea il client InfluxDB
client = InfluxDBClient(url=url, token=token, org=org)
write_api = client.write_api(write_options=SYNCHRONOUS)

# Congfiguro porta seriale
ser=serial.Serial('/dev/ttyACM0', 9600)

while True:
    #Leggi una riga di dati seriali
    data= ser.readline().decode().strip()
    print("Dati ricevuti:", data)

    #Analizza i dati
    values= list(map(float, data.split(',')))
    air_humidity, temperature, soil_moisture, light_intensity = values

    #Invio dei punti di dati a InfluxDB
    # Crea un punto di dati
    point = (
        Point("mammuth")
        .tag("location", "hallway")
        .field("air_humidity", air_humidity)
        .field("temperature", temperature)
        .field("soil_moisture", soil_moisture)
        .field("light_intensity", light_intensity)
    )
    
    # Scrivi il punto di dati nel bucket di InfluxDB
    write_api.write(bucket=bucket, org=org, record=point)
    
    print("Dati inviati a InfluxDB");
    
    # Attesa di 1 secondo tra le letture
    time.sleep(1)
