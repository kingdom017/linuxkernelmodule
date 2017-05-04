#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/init.h>

static int __init hello_init(void)
{
	char* dump_filename="/tmp/x"; //Set to the file you are targeting
	struct file *file;
	int i;
	int block_count=1; //Set me to something
	int block_size=4; //Set me to something
	loff_t pos = 0;
	mm_segment_t old_fs;

	old_fs = get_fs();  //Save the current FS segment
	set_fs(get_ds());

	file = filp_open(dump_filename, O_WRONLY|O_CREAT, 0644);

	if(file)
	{
		for(i = 0; i < block_count ; i++)
		{
			char *data="xxx"; //Wherever your data is
			if(data == NULL)
			{
				continue;
			}
   			vfs_write(file, data, block_size, &pos);
			pos = pos+block_size;

		}
		filp_close(file,NULL);
	}
	set_fs(old_fs); //Reset to save FS
	return 0;
}

static void __exit hello_cleanup(void)
{
        printk(KERN_INFO "See you,Kernel!\n");
}

module_init(hello_init);        /*进入内核的时候，调用hello_init        */
module_exit(hello_cleanup);     /*离开内核的时候，调用hello_cleanup     */
MODULE_LICENSE("GPL");          /*协议*/
