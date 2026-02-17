# Vidzhet's ConfigCreator
**A simple single-file library for making configs.**

Works similarly to std::fstream, you open a file in read or write mode, work with it, and close the file.

The architecture is based on ***Headers*** that contain some data. Header acts like a container, you can reference to it to write/read the data within the header.
```cpp
vidzhet::ConfigCreator writefile("config", Write);

writefile.additem("item1", 19.35);
auto writeheader = writefile.addheader("item2");
writeheader.write(158);
writeheader.finalize(); // must be called to close the header

writefile.close();

vidzhet::ConfigCreator readfile("config", Read);
std::cout << readfile.read_static<double>("item1") << '\n'; // trivially copyable types
auto readheader = readfile.header<int>("item2");
std::cout << readheader.read();

readfile.close();
```
A header can only store a specific type of data, either trivially copyable types or strings. You can also store a list of elements in the header.
```cpp
vidzhet::ConfigCreator writefile("config", Write);

auto listheader = writefile.addheader<std::string>("list");
listheader.write("mystring");
listheader.write("other stuff");
writeheader.finalize();

writefile.close();

vidzhet::ConfigCreator readfile("config", Read);
auto readheader = readfile.header<std::string>("list");
while (readheader.next()) {
	std::cout<< readheader.read() << std::endl;
}

readfile.close(); // readheader doesnt has to be finalized in read mode
```

Report any problems, I'm sure there is many.
