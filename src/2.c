
#define PROMISC_MODE_ON 1 // флаг включения неразборчивый режим
#define PROMISC_MODE_OFF 0 // флаг выключения неразборчивого режима

struct ifparam
{
    __u32       ip; // IP адрес
    __u32       mask;   // маска подсети
    int         mtu;    // размер MTU
    int         index;  // индекс интерфейса
} ifp;









#include <linux/socket.h>
#include <linux/ioctl.h>
#include <linux/if.h>
#include <linux/in.h>
// #include "analizator.h"

int getifconf(__u8 *intf, struct ifparam *ifp, int mode)
{
    int fd;
    struct sockaddr_in s;
    struct ifreq ifr; // см. <linux/if.h>

    memset((void *)&ifr, 0, sizeof(struct ifreq));
    if((fd = socket(AF_INET,SOCK_DGRAM,0)) < 0)	return (-1);

    sprintf(ifr.ifr_name,"%s",intf);

/*
 * Проверяем флаг режима. Если он установлен в 0, неразборчивый режим
 * необходимо отключить, поэтому сразу выполняется переход на метку setmode
 */
    if(!mode) goto setmode;

/*
 * Определяем IP адрес сетевого интерфейса
 */
    if(ioctl(fd, SIOCGIFADDR, &ifr) < 0) {
	perror("ioctl SIOCGIFADDR");
	return -1;
    }
    memset((void *)&s, 0, sizeof(struct sockaddr_in));
    memcpy((void *)&s, (void *)&ifr.ifr_addr, sizeof(struct sockaddr));
    memcpy((void *)&ifp->ip, (void *)&s.sin_addr.s_addr, sizeof(__u32));

/*
 * Определяем маску подсети
 */
    if(ioctl(fd, SIOCGIFNETMASK, &ifr) < 0) {
	perror("ioctl SIOCGIFNETMASK");
	return -1;
    }
    memset((void *)&s, 0, sizeof(struct sockaddr_in));
    memcpy((void *)&s, (void *)&ifr.ifr_netmask, sizeof(struct sockaddr));
    memcpy((void *)&ifp->mask, (void *)&s.sin_addr.s_addr, sizeof(u_long));

/*
 * Определяем размер MTU
 */
    if(ioctl(fd, SIOCGIFMTU, &ifr) < 0) {
	perror("ioctl SIOCGIFMTU");
	return -1;
    }
    ifp->mtu = ifr.ifr_mtu;

/*
 * Индекс интерфейса
 */
    if(ioctl(fd, SIOCGIFINDEX, &ifr) < 0) {
	perror("ioctl SIOCGIFINDEX");
	return -1;
    }
    ifp->index = ifr.ifr_ifindex;


/*
 * Устанавливаем заданный режим работы сетевого интерфейса
 */
setmode:

/*
 * Получаем значение флагов
 */
    if(ioctl(fd, SIOCGIFFLAGS, &ifr) < 0) {
	perror("ioctl SIOCGIFFLAGS");
	close(fd);
	return -1;
    }

/*
 * В зависимости от значения третьего параметра функции, устанавливаем
 * или снимаем флаг неразборчивого режима
 */
    if(mode) ifr.ifr_flags |= IFF_PROMISC;
    else ifr.ifr_flags &= ~(IFF_PROMISC);

/*
 * Устанавливаем новое значение флагов интерфейса
 */
    if(ioctl(fd, SIOCSIFFLAGS, &ifr) < 0) {
	perror("ioctl SIOCSIFFLAGS");
	close(fd);
	return (-1);
    }

    return 0;
}