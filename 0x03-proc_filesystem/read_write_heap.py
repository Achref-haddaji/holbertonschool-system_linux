#!/usr/bin/python3
import sys
import ctypes

def find_and_replace_string(pid, search_string, replace_string):
    try:
        process = psutil.Process(pid)
    except psutil.NoSuchProcess:
        print("Error: Invalid PID")
        sys.exit(1)
        
    # Iterate through the process's memory mappings
    for mapping in process.memory_maps():
        # Look for mappings in the heap
        if mapping.path.startswith('[heap]'):
            # Open the mapping as a file
            with open(mapping.path, 'rb+') as f:
                # Read the data from the mapping
                data = f.read()
                # Replace the search string with the replace string
                new_data = data.replace(search_string.encode(), replace_string.encode())
                # Seek to the beginning of the file
                f.seek(0)
                # Write the new data to the file
                f.write(new_data)
                # Flush the data to disk
                f.flush()
                # Use msync to make sure the data is written to memory
                addr, length = mapping.addr, mapping.length
                libc = ctypes.CDLL('libc.so.6')
                libc.msync(addr, length, libc.MS_SYNC)
    print(f"Search string '{search_string}' successfully replaced with '{replace_string}'")

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Error: Invalid number of arguments")
        print("Usage: read_write_heap.py pid search_string replace_string")
        sys.exit(1)
    else:
        pid = int(sys.argv[1])
        search_string = sys.argv[2]
        replace_string = sys.argv[3]
        find_and_replace_string(pid, search_string, replace_string)
