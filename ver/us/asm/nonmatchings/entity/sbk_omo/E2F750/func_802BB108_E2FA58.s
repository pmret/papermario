.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB108_E2FA58
/* E2FA58 802BB108 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E2FA5C 802BB10C AFBF002C */  sw        $ra, 0x2c($sp)
/* E2FA60 802BB110 AFB60028 */  sw        $s6, 0x28($sp)
/* E2FA64 802BB114 AFB50024 */  sw        $s5, 0x24($sp)
/* E2FA68 802BB118 AFB40020 */  sw        $s4, 0x20($sp)
/* E2FA6C 802BB11C AFB3001C */  sw        $s3, 0x1c($sp)
/* E2FA70 802BB120 AFB20018 */  sw        $s2, 0x18($sp)
/* E2FA74 802BB124 AFB10014 */  sw        $s1, 0x14($sp)
/* E2FA78 802BB128 0C04417A */  jal       get_entity_by_index
/* E2FA7C 802BB12C AFB00010 */   sw       $s0, 0x10($sp)
/* E2FA80 802BB130 3C07E300 */  lui       $a3, 0xe300
/* E2FA84 802BB134 34E71001 */  ori       $a3, $a3, 0x1001
/* E2FA88 802BB138 3C08F500 */  lui       $t0, 0xf500
/* E2FA8C 802BB13C 35080100 */  ori       $t0, $t0, 0x100
/* E2FA90 802BB140 3C090703 */  lui       $t1, 0x703
/* E2FA94 802BB144 3529C000 */  ori       $t1, $t1, 0xc000
/* E2FA98 802BB148 3C0AD700 */  lui       $t2, 0xd700
/* E2FA9C 802BB14C 354A0002 */  ori       $t2, $t2, 2
/* E2FAA0 802BB150 3C0DFC12 */  lui       $t5, 0xfc12
/* E2FAA4 802BB154 35AD1824 */  ori       $t5, $t5, 0x1824
/* E2FAA8 802BB158 3C0CFF33 */  lui       $t4, 0xff33
/* E2FAAC 802BB15C 358CFFFF */  ori       $t4, $t4, 0xffff
/* E2FAB0 802BB160 3C0EE300 */  lui       $t6, 0xe300
/* E2FAB4 802BB164 35CE0D01 */  ori       $t6, $t6, 0xd01
/* E2FAB8 802BB168 3C0FE300 */  lui       $t7, 0xe300
/* E2FABC 802BB16C 35EF0F00 */  ori       $t7, $t7, 0xf00
/* E2FAC0 802BB170 3C100709 */  lui       $s0, 0x709
/* E2FAC4 802BB174 36104060 */  ori       $s0, $s0, 0x4060
/* E2FAC8 802BB178 3C11071F */  lui       $s1, 0x71f
/* E2FACC 802BB17C 3631F200 */  ori       $s1, $s1, 0xf200
/* E2FAD0 802BB180 3C13F540 */  lui       $s3, 0xf540
/* E2FAD4 802BB184 36730800 */  ori       $s3, $s3, 0x800
/* E2FAD8 802BB188 3C120009 */  lui       $s2, 9
/* E2FADC 802BB18C 36524060 */  ori       $s2, $s2, 0x4060
/* E2FAE0 802BB190 3C14000F */  lui       $s4, 0xf
/* E2FAE4 802BB194 3694C07C */  ori       $s4, $s4, 0xc07c
/* E2FAE8 802BB198 3C15E300 */  lui       $s5, 0xe300
/* E2FAEC 802BB19C 36B50C00 */  ori       $s5, $s5, 0xc00
/* E2FAF0 802BB1A0 3C16E300 */  lui       $s6, 0xe300
/* E2FAF4 802BB1A4 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* E2FAF8 802BB1A8 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* E2FAFC 802BB1AC 36D61201 */  ori       $s6, $s6, 0x1201
/* E2FB00 802BB1B0 8C830000 */  lw        $v1, ($a0)
/* E2FB04 802BB1B4 3C06E700 */  lui       $a2, 0xe700
/* E2FB08 802BB1B8 0060282D */  daddu     $a1, $v1, $zero
/* E2FB0C 802BB1BC 24630008 */  addiu     $v1, $v1, 8
/* E2FB10 802BB1C0 AC830000 */  sw        $v1, ($a0)
/* E2FB14 802BB1C4 8C4B0040 */  lw        $t3, 0x40($v0)
/* E2FB18 802BB1C8 24620008 */  addiu     $v0, $v1, 8
/* E2FB1C 802BB1CC ACA60000 */  sw        $a2, ($a1)
/* E2FB20 802BB1D0 ACA00004 */  sw        $zero, 4($a1)
/* E2FB24 802BB1D4 AC820000 */  sw        $v0, ($a0)
/* E2FB28 802BB1D8 34028000 */  ori       $v0, $zero, 0x8000
/* E2FB2C 802BB1DC AC620004 */  sw        $v0, 4($v1)
/* E2FB30 802BB1E0 24620010 */  addiu     $v0, $v1, 0x10
/* E2FB34 802BB1E4 AC670000 */  sw        $a3, ($v1)
/* E2FB38 802BB1E8 AC820000 */  sw        $v0, ($a0)
/* E2FB3C 802BB1EC 3C02FD10 */  lui       $v0, 0xfd10
/* E2FB40 802BB1F0 AC620008 */  sw        $v0, 8($v1)
/* E2FB44 802BB1F4 3C020A00 */  lui       $v0, 0xa00
/* E2FB48 802BB1F8 244218A0 */  addiu     $v0, $v0, 0x18a0
/* E2FB4C 802BB1FC AC62000C */  sw        $v0, 0xc($v1)
/* E2FB50 802BB200 24620018 */  addiu     $v0, $v1, 0x18
/* E2FB54 802BB204 AC820000 */  sw        $v0, ($a0)
/* E2FB58 802BB208 3C02E800 */  lui       $v0, 0xe800
/* E2FB5C 802BB20C AC620010 */  sw        $v0, 0x10($v1)
/* E2FB60 802BB210 24620020 */  addiu     $v0, $v1, 0x20
/* E2FB64 802BB214 AC600014 */  sw        $zero, 0x14($v1)
/* E2FB68 802BB218 AC820000 */  sw        $v0, ($a0)
/* E2FB6C 802BB21C 3C020700 */  lui       $v0, 0x700
/* E2FB70 802BB220 AC62001C */  sw        $v0, 0x1c($v1)
/* E2FB74 802BB224 24620028 */  addiu     $v0, $v1, 0x28
/* E2FB78 802BB228 3C05E600 */  lui       $a1, 0xe600
/* E2FB7C 802BB22C AC680018 */  sw        $t0, 0x18($v1)
/* E2FB80 802BB230 AC820000 */  sw        $v0, ($a0)
/* E2FB84 802BB234 24620030 */  addiu     $v0, $v1, 0x30
/* E2FB88 802BB238 AC650020 */  sw        $a1, 0x20($v1)
/* E2FB8C 802BB23C AC600024 */  sw        $zero, 0x24($v1)
/* E2FB90 802BB240 AC820000 */  sw        $v0, ($a0)
/* E2FB94 802BB244 3C02F000 */  lui       $v0, 0xf000
/* E2FB98 802BB248 AC620028 */  sw        $v0, 0x28($v1)
/* E2FB9C 802BB24C 24620038 */  addiu     $v0, $v1, 0x38
/* E2FBA0 802BB250 AC69002C */  sw        $t1, 0x2c($v1)
/* E2FBA4 802BB254 AC820000 */  sw        $v0, ($a0)
/* E2FBA8 802BB258 24620040 */  addiu     $v0, $v1, 0x40
/* E2FBAC 802BB25C AC660030 */  sw        $a2, 0x30($v1)
/* E2FBB0 802BB260 AC600034 */  sw        $zero, 0x34($v1)
/* E2FBB4 802BB264 AC820000 */  sw        $v0, ($a0)
/* E2FBB8 802BB268 2402FFFF */  addiu     $v0, $zero, -1
/* E2FBBC 802BB26C AC62003C */  sw        $v0, 0x3c($v1)
/* E2FBC0 802BB270 24620048 */  addiu     $v0, $v1, 0x48
/* E2FBC4 802BB274 AC6A0038 */  sw        $t2, 0x38($v1)
/* E2FBC8 802BB278 AC820000 */  sw        $v0, ($a0)
/* E2FBCC 802BB27C 24620050 */  addiu     $v0, $v1, 0x50
/* E2FBD0 802BB280 AC6D0040 */  sw        $t5, 0x40($v1)
/* E2FBD4 802BB284 AC6C0044 */  sw        $t4, 0x44($v1)
/* E2FBD8 802BB288 AC820000 */  sw        $v0, ($a0)
/* E2FBDC 802BB28C 24620058 */  addiu     $v0, $v1, 0x58
/* E2FBE0 802BB290 AC6E0048 */  sw        $t6, 0x48($v1)
/* E2FBE4 802BB294 AC60004C */  sw        $zero, 0x4c($v1)
/* E2FBE8 802BB298 AC820000 */  sw        $v0, ($a0)
/* E2FBEC 802BB29C 24620060 */  addiu     $v0, $v1, 0x60
/* E2FBF0 802BB2A0 AC6F0050 */  sw        $t7, 0x50($v1)
/* E2FBF4 802BB2A4 AC600054 */  sw        $zero, 0x54($v1)
/* E2FBF8 802BB2A8 AC820000 */  sw        $v0, ($a0)
/* E2FBFC 802BB2AC 3C02FD50 */  lui       $v0, 0xfd50
/* E2FC00 802BB2B0 AC620058 */  sw        $v0, 0x58($v1)
/* E2FC04 802BB2B4 3C020A00 */  lui       $v0, 0xa00
/* E2FC08 802BB2B8 244214A0 */  addiu     $v0, $v0, 0x14a0
/* E2FC0C 802BB2BC AC62005C */  sw        $v0, 0x5c($v1)
/* E2FC10 802BB2C0 24620068 */  addiu     $v0, $v1, 0x68
/* E2FC14 802BB2C4 AC820000 */  sw        $v0, ($a0)
/* E2FC18 802BB2C8 3C02F550 */  lui       $v0, 0xf550
/* E2FC1C 802BB2CC AC620060 */  sw        $v0, 0x60($v1)
/* E2FC20 802BB2D0 24620070 */  addiu     $v0, $v1, 0x70
/* E2FC24 802BB2D4 AC700064 */  sw        $s0, 0x64($v1)
/* E2FC28 802BB2D8 AC820000 */  sw        $v0, ($a0)
/* E2FC2C 802BB2DC 24620078 */  addiu     $v0, $v1, 0x78
/* E2FC30 802BB2E0 AC650068 */  sw        $a1, 0x68($v1)
/* E2FC34 802BB2E4 AC60006C */  sw        $zero, 0x6c($v1)
/* E2FC38 802BB2E8 AC820000 */  sw        $v0, ($a0)
/* E2FC3C 802BB2EC 3C02F300 */  lui       $v0, 0xf300
/* E2FC40 802BB2F0 AC620070 */  sw        $v0, 0x70($v1)
/* E2FC44 802BB2F4 24620080 */  addiu     $v0, $v1, 0x80
/* E2FC48 802BB2F8 AC710074 */  sw        $s1, 0x74($v1)
/* E2FC4C 802BB2FC AC820000 */  sw        $v0, ($a0)
/* E2FC50 802BB300 24620088 */  addiu     $v0, $v1, 0x88
/* E2FC54 802BB304 AC660078 */  sw        $a2, 0x78($v1)
/* E2FC58 802BB308 AC60007C */  sw        $zero, 0x7c($v1)
/* E2FC5C 802BB30C AC820000 */  sw        $v0, ($a0)
/* E2FC60 802BB310 24620090 */  addiu     $v0, $v1, 0x90
/* E2FC64 802BB314 3C05F200 */  lui       $a1, 0xf200
/* E2FC68 802BB318 AC730080 */  sw        $s3, 0x80($v1)
/* E2FC6C 802BB31C AC720084 */  sw        $s2, 0x84($v1)
/* E2FC70 802BB320 AC820000 */  sw        $v0, ($a0)
/* E2FC74 802BB324 24620098 */  addiu     $v0, $v1, 0x98
/* E2FC78 802BB328 AC650088 */  sw        $a1, 0x88($v1)
/* E2FC7C 802BB32C AC74008C */  sw        $s4, 0x8c($v1)
/* E2FC80 802BB330 AC820000 */  sw        $v0, ($a0)
/* E2FC84 802BB334 3C020008 */  lui       $v0, 8
/* E2FC88 802BB338 AC620094 */  sw        $v0, 0x94($v1)
/* E2FC8C 802BB33C 246200A0 */  addiu     $v0, $v1, 0xa0
/* E2FC90 802BB340 AC750090 */  sw        $s5, 0x90($v1)
/* E2FC94 802BB344 AC820000 */  sw        $v0, ($a0)
/* E2FC98 802BB348 24022000 */  addiu     $v0, $zero, 0x2000
/* E2FC9C 802BB34C AC62009C */  sw        $v0, 0x9c($v1)
/* E2FCA0 802BB350 246200A8 */  addiu     $v0, $v1, 0xa8
/* E2FCA4 802BB354 AC760098 */  sw        $s6, 0x98($v1)
/* E2FCA8 802BB358 AC820000 */  sw        $v0, ($a0)
/* E2FCAC 802BB35C 81620003 */  lb        $v0, 3($t3)
/* E2FCB0 802BB360 00021080 */  sll       $v0, $v0, 2
/* E2FCB4 802BB364 30420FFF */  andi      $v0, $v0, 0xfff
/* E2FCB8 802BB368 00021300 */  sll       $v0, $v0, 0xc
/* E2FCBC 802BB36C 00451025 */  or        $v0, $v0, $a1
/* E2FCC0 802BB370 AC6200A0 */  sw        $v0, 0xa0($v1)
/* E2FCC4 802BB374 81620003 */  lb        $v0, 3($t3)
/* E2FCC8 802BB378 2442007C */  addiu     $v0, $v0, 0x7c
/* E2FCCC 802BB37C 00021080 */  sll       $v0, $v0, 2
/* E2FCD0 802BB380 30420FFF */  andi      $v0, $v0, 0xfff
/* E2FCD4 802BB384 00021300 */  sll       $v0, $v0, 0xc
/* E2FCD8 802BB388 3442007C */  ori       $v0, $v0, 0x7c
/* E2FCDC 802BB38C AC6200A4 */  sw        $v0, 0xa4($v1)
/* E2FCE0 802BB390 8FBF002C */  lw        $ra, 0x2c($sp)
/* E2FCE4 802BB394 8FB60028 */  lw        $s6, 0x28($sp)
/* E2FCE8 802BB398 8FB50024 */  lw        $s5, 0x24($sp)
/* E2FCEC 802BB39C 8FB40020 */  lw        $s4, 0x20($sp)
/* E2FCF0 802BB3A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* E2FCF4 802BB3A4 8FB20018 */  lw        $s2, 0x18($sp)
/* E2FCF8 802BB3A8 8FB10014 */  lw        $s1, 0x14($sp)
/* E2FCFC 802BB3AC 8FB00010 */  lw        $s0, 0x10($sp)
/* E2FD00 802BB3B0 03E00008 */  jr        $ra
/* E2FD04 802BB3B4 27BD0030 */   addiu    $sp, $sp, 0x30
