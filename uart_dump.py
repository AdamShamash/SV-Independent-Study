import serial
import argparse


# Press Ctrl + C in the terminal to stop reading from the serial port
# Terminal Command: python uart_dump.py --port COM4 --baudrate 57600 --count 100 --output bytes.txt
# *Note, replace "COM3" with correct COM, replace baudrate with correct baudrate, and replace count
#  with amount of bytes you want to count

# file path: "C:\Users\adam2\OneDrive\Documents\SystemVerilogStudy\SV-Independent-Study\uart.py"


def main():
    parser = argparse.ArgumentParser(description="Read UART bytes into an array and dump to a text file.")
    parser.add_argument('--port', required=True, help='UART port (e.g. COM3 or /dev/ttyUSB0)')
    parser.add_argument('--baudrate', type=int, default=9600, help='Baud rate (default: 9600)')
    parser.add_argument('--count', type=int, help='Number of bytes to read before exiting')
    parser.add_argument('--output', default='output.txt', help='Output filename (default: output.txt)')
    args = parser.parse_args()

    ser = serial.Serial(args.port, args.baudrate, timeout=1)
    bytes_list = []

    try:
        if args.count:
            while len(bytes_list) < args.count:
                b = ser.read(1)
                if b:
                    bytes_list.append(b[0])
        else:
            print("Reading bytes... press Ctrl+C to stop.")
            while True:
                b = ser.read(1)
                if b:
                    bytes_list.append(b[0])
    except KeyboardInterrupt:
        print("\nStopped by user.")
    finally:
        ser.close()

    with open(args.output, 'w') as f:
        for i, val in enumerate(bytes_list):
            f.write(f'Byte [{i}] : {val:#04x}\n')

    print(f"Wrote {len(bytes_list)} bytes to {args.output}")

if __name__ == '__main__':
    main()
