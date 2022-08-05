#include "manager.h"
#include "sale.h"
#include "login_menus.h"

int main(int argc,const char* argv[])
{
		//比较备份文件与原文件大小，读取小的文件(处理文件被污染)
		if(file_size("管理员2.dat") > file_size("管理员.dat"))
		{
			manager_cnt = load_data(manager,sizeof(manager),"管理员.dat") / sizeof(Manager);
		}
		else
		{
			manager_cnt = load_data(manager,sizeof(manager),"管理员2.dat") / sizeof(Manager);			
		}
		if(file_size("commodity2.dat") > file_size("commodity.dat"))
		{
			commodity_cnt = load_data(commodity,sizeof(commodity),"商品.dat") / sizeof(Commodity);			
		}
		else
		{
			commodity_cnt = load_data(commodity,sizeof(commodity),"商品2.dat") / sizeof(Commodity);			
		}
		if(file_size("后勤2.dat") > file_size("后勤.dat"))
		{
			logistic_cnt = load_data(logistics,sizeof(logistics),"后勤.dat") / sizeof(Logistic);
		}
		else
		{
			logistic_cnt = load_data(logistics,sizeof(logistics),"后勤2.dat") / sizeof(Logistic);			
		}
		if(file_size("vip2.dat") > file_size("vip.dat"))
		{
			vip_cnt = load_data(vip,sizeof(vip),"vip.dat") / sizeof(Vip);
		}
		else
		{
			vip_cnt = load_data(vip,sizeof(vip),"vip2.dat") / sizeof(Vip);			
		}
		if(file_size("账户2.dat") > file_size("账户.dat"))
		{
			account_cnt = load_data(account,sizeof(account),"账户.dat") / sizeof(Account);
		}
		else
		{
			account_cnt = load_data(account,sizeof(account),"账户2.dat") / sizeof(Account);			
		}
	for(;;)
	{
		main_menu();//加载主界面
		printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
		switch(get_cmd('1','3'))
		{
		case '1': goods_menu(); break;    //进入商品界面，供用户挑选商品并结账
		case '2': login_menus(); break;  //进入登录界面
		case '3':
			//将数据保存到相应的文本中
				save_data(manager,sizeof(Manager)*manager_cnt,"管理员.dat");
				save_data(commodity,sizeof(Commodity)*commodity_cnt,"商品.dat");
				save_data(vip,sizeof(Vip)*vip_cnt,"vip.dat"); 
				save_data(logistics,sizeof(Logistic)*logistic_cnt,"后勤.dat");
				save_data(logistics,sizeof(Logistic)*logistic_cnt,"账户.dat");	
			//文件备份	
				save_data(manager,sizeof(Manager)*manager_cnt,"管理员2.dat");
				save_data(commodity,sizeof(Commodity)*commodity_cnt,"商品2.dat");
				save_data(vip,sizeof(Vip)*vip_cnt,"vip2.dat"); 
				save_data(logistics,sizeof(Logistic)*logistic_cnt,"后勤2.dat");	
				save_data(account,sizeof(Account)*account_cnt,"账户2.dat");						
				return 0;
		}
	}
}
