#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x14522340, "module_layout" },
	{ 0x3e14d8d6, "blk_init_queue" },
	{ 0x573939cb, "alloc_disk" },
	{ 0xe5a6404e, "blk_cleanup_queue" },
	{ 0xd6ee688f, "vmalloc" },
	{ 0xd691cba2, "malloc_sizes" },
	{ 0x999e8297, "vfree" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0xea147363, "printk" },
	{ 0xce4db10e, "del_gendisk" },
	{ 0xb4390f9a, "mcount" },
	{ 0x71a50dbc, "register_blkdev" },
	{ 0xb5a459dc, "unregister_blkdev" },
	{ 0x8aa14eee, "put_disk" },
	{ 0xc7d4165d, "__blk_end_request_cur" },
	{ 0xbc2262ee, "blk_fetch_request" },
	{ 0x2044fa9e, "kmem_cache_alloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x236c8c64, "memcpy" },
	{ 0xd7936fb1, "add_disk" },
	{ 0xe40b105c, "blk_queue_logical_block_size" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "C313583EED13288264A6B10");

static const struct rheldata _rheldata __used
__attribute__((section(".rheldata"))) = {
	.rhel_major = 6,
	.rhel_minor = 4,
};
