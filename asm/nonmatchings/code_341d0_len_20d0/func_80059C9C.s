.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80059C9C
/* 03509C 80059C9C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0350A0 80059CA0 2402000E */  addiu $v0, $zero, 0xe
/* 0350A4 80059CA4 3C03800A */  lui   $v1, 0x800a
/* 0350A8 80059CA8 246341C0 */  addiu $v1, $v1, 0x41c0
/* 0350AC 80059CAC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0350B0 80059CB0 AFB00018 */  sw    $s0, 0x18($sp)
.L80059CB4:
/* 0350B4 80059CB4 AC600000 */  sw    $zero, ($v1)
/* 0350B8 80059CB8 2442FFFF */  addiu $v0, $v0, -1
/* 0350BC 80059CBC 0441FFFD */  bgez  $v0, .L80059CB4
/* 0350C0 80059CC0 2463FFE0 */   addiu $v1, $v1, -0x20
/* 0350C4 80059CC4 2402005F */  addiu $v0, $zero, 0x5f
/* 0350C8 80059CC8 3C03800B */  lui   $v1, 0x800b
/* 0350CC 80059CCC 24634514 */  addiu $v1, $v1, 0x4514
.L80059CD0:
/* 0350D0 80059CD0 AC600000 */  sw    $zero, ($v1)
/* 0350D4 80059CD4 2442FFFF */  addiu $v0, $v0, -1
/* 0350D8 80059CD8 0441FFFD */  bgez  $v0, .L80059CD0
/* 0350DC 80059CDC 2463FFFC */   addiu $v1, $v1, -4
/* 0350E0 80059CE0 0C019A58 */  jal   osUnmapTLBAll
/* 0350E4 80059CE4 00000000 */   nop   
/* 0350E8 80059CE8 3C0300FF */  lui   $v1, 0xff
/* 0350EC 80059CEC 3463FFFF */  ori   $v1, $v1, 0xffff
/* 0350F0 80059CF0 24040010 */  addiu $a0, $zero, 0x10
/* 0350F4 80059CF4 0000282D */  daddu $a1, $zero, $zero
/* 0350F8 80059CF8 3C10E020 */  lui   $s0, 0xe020
/* 0350FC 80059CFC 26100000 */  addiu $s0, $s0, 0
/* 035100 80059D00 0200302D */  daddu $a2, $s0, $zero
/* 035104 80059D04 2402FFFF */  addiu $v0, $zero, -1
/* 035108 80059D08 3C07801A */  lui   $a3, 0x801a
/* 03510C 80059D0C 24E76000 */  addiu $a3, $a3, 0x6000
/* 035110 80059D10 00E33824 */  and   $a3, $a3, $v1
/* 035114 80059D14 AFA20010 */  sw    $v0, 0x10($sp)
/* 035118 80059D18 0C0199E8 */  jal   osMapTLB
/* 03511C 80059D1C AFA20014 */   sw    $v0, 0x14($sp)
/* 035120 80059D20 3C040032 */  lui   $a0, 0x32
/* 035124 80059D24 24845AD0 */  addiu $a0, $a0, 0x5ad0
/* 035128 80059D28 3C050032 */  lui   $a1, 0x32
/* 03512C 80059D2C 24A56410 */  addiu $a1, $a1, 0x6410
/* 035130 80059D30 0C00A5CF */  jal   dma_copy
/* 035134 80059D34 0200302D */   daddu $a2, $s0, $zero
/* 035138 80059D38 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03513C 80059D3C 8FB00018 */  lw    $s0, 0x18($sp)
/* 035140 80059D40 03E00008 */  jr    $ra
/* 035144 80059D44 27BD0020 */   addiu $sp, $sp, 0x20

/* 035148 80059D48 03E00008 */  jr    $ra
/* 03514C 80059D4C 00000000 */   nop   

