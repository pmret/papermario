.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_effect_data
/* 3509C 80059C9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 350A0 80059CA0 2402000E */  addiu     $v0, $zero, 0xe
/* 350A4 80059CA4 3C03800A */  lui       $v1, %hi(D_800A41C0)
/* 350A8 80059CA8 246341C0 */  addiu     $v1, $v1, %lo(D_800A41C0)
/* 350AC 80059CAC AFBF001C */  sw        $ra, 0x1c($sp)
/* 350B0 80059CB0 AFB00018 */  sw        $s0, 0x18($sp)
.L80059CB4:
/* 350B4 80059CB4 AC600000 */  sw        $zero, ($v1)
/* 350B8 80059CB8 2442FFFF */  addiu     $v0, $v0, -1
/* 350BC 80059CBC 0441FFFD */  bgez      $v0, .L80059CB4
/* 350C0 80059CC0 2463FFE0 */   addiu    $v1, $v1, -0x20
/* 350C4 80059CC4 2402005F */  addiu     $v0, $zero, 0x5f
/* 350C8 80059CC8 3C03800B */  lui       $v1, %hi(D_800B4514)
/* 350CC 80059CCC 24634514 */  addiu     $v1, $v1, %lo(D_800B4514)
.L80059CD0:
/* 350D0 80059CD0 AC600000 */  sw        $zero, ($v1)
/* 350D4 80059CD4 2442FFFF */  addiu     $v0, $v0, -1
/* 350D8 80059CD8 0441FFFD */  bgez      $v0, .L80059CD0
/* 350DC 80059CDC 2463FFFC */   addiu    $v1, $v1, -4
/* 350E0 80059CE0 0C019A58 */  jal       osUnmapTLBAll
/* 350E4 80059CE4 00000000 */   nop
/* 350E8 80059CE8 3C0300FF */  lui       $v1, 0xff
/* 350EC 80059CEC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 350F0 80059CF0 24040010 */  addiu     $a0, $zero, 0x10
/* 350F4 80059CF4 0000282D */  daddu     $a1, $zero, $zero
/* 350F8 80059CF8 3C10E020 */  lui       $s0, %hi(D_E0200000)
/* 350FC 80059CFC 26100000 */  addiu     $s0, $s0, %lo(D_E0200000)
/* 35100 80059D00 0200302D */  daddu     $a2, $s0, $zero
/* 35104 80059D04 2402FFFF */  addiu     $v0, $zero, -1
/* 35108 80059D08 3C07801A */  lui       $a3, %hi(D_801A6000)
/* 3510C 80059D0C 24E76000 */  addiu     $a3, $a3, %lo(D_801A6000)
/* 35110 80059D10 00E33824 */  and       $a3, $a3, $v1
/* 35114 80059D14 AFA20010 */  sw        $v0, 0x10($sp)
/* 35118 80059D18 0C0199E8 */  jal       osMapTLB
/* 3511C 80059D1C AFA20014 */   sw       $v0, 0x14($sp)
/* 35120 80059D20 3C040032 */  lui       $a0, 0x32
/* 35124 80059D24 24845AD0 */  addiu     $a0, $a0, 0x5ad0
/* 35128 80059D28 3C050032 */  lui       $a1, 0x32
/* 3512C 80059D2C 24A56410 */  addiu     $a1, $a1, 0x6410
/* 35130 80059D30 0C00A5CF */  jal       dma_copy
/* 35134 80059D34 0200302D */   daddu    $a2, $s0, $zero
/* 35138 80059D38 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3513C 80059D3C 8FB00018 */  lw        $s0, 0x18($sp)
/* 35140 80059D40 03E00008 */  jr        $ra
/* 35144 80059D44 27BD0020 */   addiu    $sp, $sp, 0x20
