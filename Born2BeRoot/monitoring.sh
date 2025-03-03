#!/bin/bash
#Architecture
arch=$(uname -a)
#Physical Cores
cpuph=$(grep "physical id" /proc/cpuinfo | wc -l)
#Virtual Cores
cpuv=$(grep  "#processor" /proc/cpuinfo | wc -l)
#RAM Usage
ramus=$(free --mega | awk '$1 == "Mem:" {printf("%d/%dMB (%.2f%%)\n", $3, $2, $3/$2*100)}')
#Disk Usage
diskus=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{mem_use += $3} {total_mem += $2} END {printf("%d/%dGb (%d%%)\n"), mem_use, total_mem/1000, mem_use/total_mem*100}')
#CPU Usage
cpuus=$(vmstat | awk 'NR==3 {printf("%.2f%%\n", 100-$15)}')
#Last boot
lastb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
#LVM use
lvmus=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
#TCP Connections
tcpc=$(ss -ta | grep ESTAB | wc -l)
#User log
ulog=$(users | wc -w)
#Network info
ip=$(hostname -I)
net=$(ip link | grep "link/ether" | awk '{print $2}')
#Sudo commands
sudocom=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	#Architecture : $arch
	#CPU physical : $cpuph
	#vCPU : $cpuv
	#Memory Usage : $ramus
	#Disk Usage : $diskus
	#CPU load : $cpuus
	#Last boot : $lastb
	#LVM use : $lvmus
	#TCP Connections : $tcpc ESTABLISHED CONNECTIONS
	#User log : $ulog
	#Network : IP $ip ($net)
	#Sudo : $sudocom"
