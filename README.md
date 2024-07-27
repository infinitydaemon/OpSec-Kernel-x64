![Github Banner](https://cwd.systems/img/banner.png)

```python
class CWD_OpSec():
    
  def __init__(self):
    self.name = "cwd";
    self.current.release = "The Dark Hadou for x86/64";
    self.username = "cwdsystems";
    self.location = "KyrgzRepublic";
    self.protonmail = "@cwdsystems";
    self.web = "https://cwd.systems";
    self.languages ="Objective C, Python,Bash,Perl";
  
  def __str__(self):
    return self.name

if __name__ == '__main__':
    me = CWD_OpSec()
```

CWD SYSTEMS Linux
=================

Linux Kernel that was tuned and built as Brooklyn Supreme is now OpSec Kernel used in CWD & 0KN Appliances. Numerous optimizations and tweaks have been applied for high availability and network wide security on a packaged build which is shipped on CWD and 0KN appliances. Each appliance has its own different kernel and NOT a generic OpSec release due to the fact that each appliance has a different purpose. The build instructions vary when compared to official kernel.org build instructions. Follow the steps to build the OpSec Kernel for your machine on Debian based distros.

```bash
git clone https://github.com/infinitydaemon/OpSec-Kernel-x64.git
chmod +x build-Opsec64.sh
./build-Opsec64.sh
```

After all stages of the build process are completed, proceed to reboot by answering "Yes."

```bash
uname -rs to verify if the kernel is loaded and activated.
```
Proceed to Stage 2 to enable hardened TCP/IP settings.

```bash
cd Opsec-Kernel-x64
chmod +x stage2-Opsec64.sh
./stage2-Opsec64.sh
```

In order to build the documentation, use ``make htmldocs`` or
``make pdfdocs``.  The formatted documentation can also be read online at:

    https://www.kernel.org/doc/html/latest/

We are dedicated to pushing the boundaries of innovation with our projects. If you appreciate our work and want to support our Research & Development efforts, consider making a donation. Your contributions help us continue our mission and achieve greater milestones.  

### Crypto Donations

- **Litecoin (LTC)**: `LfrJzpybM8ZRTFcd8HYfH4NXFtPKpr5Dpg`  
- **Bitcoin (BTC)**: `13zp3jdZ5utX5vmZaZiDyJtam8daS4uBpC`  
- **Ethereum (ERC20)**: `0x822803b26e4c235658085341aa113555d35e0b4c`  
- **Dogecoin (DOGE)**: `DJTRkmhwhG7W8t7WvAddZBnNkKWML6nHqJ`  

Thank you for your generosity and support!
