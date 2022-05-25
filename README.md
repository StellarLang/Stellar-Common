<img src="./asset/stellar.png" align="right" width="128px" alt="Stellar Icon"/>

# Stellar Common
Stellar Common is the core library containing all the common classes necessary to build the Stellar vm, compiler, and other Stellar tooling.

## Compiling
This project is meant to be consumed as a library. On Linux, run these steps to install the shared library to your system lib and include:

```bash
mkdir build
cmake . -Bcmake-build-debug -G "Unix Makefiles"
cd cmake-build-debug/source
sudo make install
```

## Contributing
Please keep your contributions on-topic and be kind. Contributions of any kind are always welcome!

## License
This project is licensed under the [MIT License](LICENSE).