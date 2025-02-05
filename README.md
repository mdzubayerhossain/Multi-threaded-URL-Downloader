# Multi-threaded URL Downloader

A high-performance multi-threaded URL downloader written in C using **libcurl** and **pthreads**. This program allows you to download multiple files concurrently, increasing efficiency and speed.

## Features
✅ Multi-threaded downloads (up to 5 files simultaneously)  
✅ Uses **libcurl** for efficient file transfers  
✅ Supports large files with robust error handling  
✅ Lightweight and optimized for performance  
✅ Works on Linux, macOS, and Windows  

## Installation

### 1. Install libcurl (if not already installed)
#### Linux (Ubuntu/Debian)
```sh
sudo apt install libcurl4-openssl-dev
```
#### macOS (Homebrew)
```sh
brew install curl
```
#### Windows (MinGW)
Download and install libcurl from [cURL official website](https://curl.se/download.html). Ensure it's properly linked during compilation.

### 2. Clone the Repository
```sh
git clone https://github.com/mdzubayerhossain/Multi-threaded-URL-Downloader.git
cd multi-threaded-url-downloader
```

### 3. Compile the Program
```sh
gcc -o downloader downloader.c -lcurl -lpthread
```

### 4. Run the Program
```sh
./downloader
```

## Usage
By default, the program downloads 5 sample files from the internet. To modify the URLs and filenames, update the `DownloadTask` array in `downloader.c`.

Example:
```c
DownloadTask tasks[MAX_THREADS] = {
    {"https://example.com/file1.jpg", "file1.jpg"},
    {"https://example.com/file2.jpg", "file2.jpg"},
};
```

## Contributing
We welcome contributions! If you want to improve this project, feel free to:
- Open an **issue** for bug reports or feature requests.
- Submit a **pull request** with improvements.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contact
For any questions or suggestions, reach out via:
- **GitHub Issues**: [https://github.com/yourusername/multi-threaded-url-downloader/issues](https://github.com/mdzubayerhossain/multi-threaded-url-downloader/issues)
- **Email**: mdzubayerhossainpatowari@gmail.com

## Star the Repo ⭐
If you found this project helpful, please **star** the repo to support future development!

---
🚀 **Happy Coding!** 🚀

