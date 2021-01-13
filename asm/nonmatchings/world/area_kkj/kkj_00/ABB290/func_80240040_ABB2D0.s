.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_ABB2D0
/* ABB2D0 80240040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ABB2D4 80240044 AFBF0014 */  sw        $ra, 0x14($sp)
/* ABB2D8 80240048 AFB00010 */  sw        $s0, 0x10($sp)
/* ABB2DC 8024004C 8C82000C */  lw        $v0, 0xc($a0)
/* ABB2E0 80240050 8C450000 */  lw        $a1, ($v0)
/* ABB2E4 80240054 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* ABB2E8 80240058 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* ABB2EC 8024005C 0C0B1EAF */  jal       get_variable
/* ABB2F0 80240060 00000000 */   nop
/* ABB2F4 80240064 14400005 */  bnez      $v0, .L8024007C
/* ABB2F8 80240068 00000000 */   nop
/* ABB2FC 8024006C 3C028024 */  lui       $v0, %hi(D_8024160C)
/* ABB300 80240070 2442160C */  addiu     $v0, $v0, %lo(D_8024160C)
/* ABB304 80240074 08090022 */  j         .L80240088
/* ABB308 80240078 AE0200D0 */   sw       $v0, 0xd0($s0)
.L8024007C:
/* ABB30C 8024007C 3C028024 */  lui       $v0, %hi(func_8024162C_9F606C)
/* ABB310 80240080 2442162C */  addiu     $v0, $v0, %lo(func_8024162C_9F606C)
/* ABB314 80240084 AE0200D0 */  sw        $v0, 0xd0($s0)
.L80240088:
/* ABB318 80240088 8E030000 */  lw        $v1, ($s0)
/* ABB31C 8024008C 34630010 */  ori       $v1, $v1, 0x10
/* ABB320 80240090 AE030000 */  sw        $v1, ($s0)
/* ABB324 80240094 8FBF0014 */  lw        $ra, 0x14($sp)
/* ABB328 80240098 8FB00010 */  lw        $s0, 0x10($sp)
/* ABB32C 8024009C 24020002 */  addiu     $v0, $zero, 2
/* ABB330 802400A0 03E00008 */  jr        $ra
/* ABB334 802400A4 27BD0018 */   addiu    $sp, $sp, 0x18
/* ABB338 802400A8 00000000 */  nop
/* ABB33C 802400AC 00000000 */  nop
