.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8025D90C
/* 18C1EC 8025D90C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18C1F0 8025D910 AFB00018 */  sw    $s0, 0x18($sp)
/* 18C1F4 8025D914 0080802D */  daddu $s0, $a0, $zero
/* 18C1F8 8025D918 AFBF001C */  sw    $ra, 0x1c($sp)
/* 18C1FC 8025D91C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 18C200 8025D920 8E0400C0 */  lw    $a0, 0xc0($s0)
/* 18C204 8025D924 00853021 */  addu  $a2, $a0, $a1
/* 18C208 8025D928 80C308BC */  lb    $v1, 0x8bc($a2)
/* 18C20C 8025D92C 10600005 */  beqz  $v1, .L8025D944
/* 18C210 8025D930 24020001 */   addiu $v0, $zero, 1
/* 18C214 8025D934 10620009 */  beq   $v1, $v0, .L8025D95C
/* 18C218 8025D938 00051040 */   sll   $v0, $a1, 1
/* 18C21C 8025D93C 08097693 */  j     .L8025DA4C
/* 18C220 8025D940 00000000 */   nop   

.L8025D944:
/* 18C224 8025D944 00051040 */  sll   $v0, $a1, 1
/* 18C228 8025D948 00821021 */  addu  $v0, $a0, $v0
/* 18C22C 8025D94C A44008BE */  sh    $zero, 0x8be($v0)
/* 18C230 8025D950 24020001 */  addiu $v0, $zero, 1
/* 18C234 8025D954 A0C208BC */  sb    $v0, 0x8bc($a2)
/* 18C238 8025D958 00051040 */  sll   $v0, $a1, 1
.L8025D95C:
/* 18C23C 8025D95C 00821821 */  addu  $v1, $a0, $v0
/* 18C240 8025D960 946208BE */  lhu   $v0, 0x8be($v1)
/* 18C244 8025D964 24420001 */  addiu $v0, $v0, 1
/* 18C248 8025D968 A46208BE */  sh    $v0, 0x8be($v1)
/* 18C24C 8025D96C 00021400 */  sll   $v0, $v0, 0x10
/* 18C250 8025D970 00021403 */  sra   $v0, $v0, 0x10
/* 18C254 8025D974 28420004 */  slti  $v0, $v0, 4
/* 18C258 8025D978 14400034 */  bnez  $v0, .L8025DA4C
/* 18C25C 8025D97C 00000000 */   nop   
/* 18C260 8025D980 A46008BE */  sh    $zero, 0x8be($v1)
/* 18C264 8025D984 C60C0064 */  lwc1  $f12, 0x64($s0)
/* 18C268 8025D988 0C00A6C9 */  jal   clamp_angle
/* 18C26C 8025D98C 46006307 */   neg.s $f12, $f12
/* 18C270 8025D990 3C0140C9 */  lui   $at, 0x40c9
/* 18C274 8025D994 34210FD0 */  ori   $at, $at, 0xfd0
/* 18C278 8025D998 44811000 */  mtc1  $at, $f2
/* 18C27C 8025D99C 00000000 */  nop   
/* 18C280 8025D9A0 46020502 */  mul.s $f20, $f0, $f2
/* 18C284 8025D9A4 00000000 */  nop   
/* 18C288 8025D9A8 3C0143B4 */  lui   $at, 0x43b4
/* 18C28C 8025D9AC 44810000 */  mtc1  $at, $f0
/* 18C290 8025D9B0 00000000 */  nop   
/* 18C294 8025D9B4 4600A503 */  div.s $f20, $f20, $f0
/* 18C298 8025D9B8 0C00A85B */  jal   sin_rad
/* 18C29C 8025D9BC 4600A306 */   mov.s $f12, $f20
/* 18C2A0 8025D9C0 4600A306 */  mov.s $f12, $f20
/* 18C2A4 8025D9C4 0C00A874 */  jal   cos_rad
/* 18C2A8 8025D9C8 46000506 */   mov.s $f20, $f0
/* 18C2AC 8025D9CC 92020072 */  lbu   $v0, 0x72($s0)
/* 18C2B0 8025D9D0 44822000 */  mtc1  $v0, $f4
/* 18C2B4 8025D9D4 00000000 */  nop   
/* 18C2B8 8025D9D8 46802120 */  cvt.s.w $f4, $f4
/* 18C2BC 8025D9DC 46142182 */  mul.s $f6, $f4, $f20
/* 18C2C0 8025D9E0 00000000 */  nop   
/* 18C2C4 8025D9E4 46002102 */  mul.s $f4, $f4, $f0
/* 18C2C8 8025D9E8 00000000 */  nop   
/* 18C2CC 8025D9EC 3C013E4C */  lui   $at, 0x3e4c
/* 18C2D0 8025D9F0 3421CCCD */  ori   $at, $at, 0xcccd
/* 18C2D4 8025D9F4 44811000 */  mtc1  $at, $f2
/* 18C2D8 8025D9F8 00000000 */  nop   
/* 18C2DC 8025D9FC 46023182 */  mul.s $f6, $f6, $f2
/* 18C2E0 8025DA00 00000000 */  nop   
/* 18C2E4 8025DA04 46022102 */  mul.s $f4, $f4, $f2
/* 18C2E8 8025DA08 00000000 */  nop   
/* 18C2EC 8025DA0C C6020058 */  lwc1  $f2, 0x58($s0)
/* 18C2F0 8025DA10 46061080 */  add.s $f2, $f2, $f6
/* 18C2F4 8025DA14 C6060060 */  lwc1  $f6, 0x60($s0)
/* 18C2F8 8025DA18 C608005C */  lwc1  $f8, 0x5c($s0)
/* 18C2FC 8025DA1C 46043180 */  add.s $f6, $f6, $f4
/* 18C300 8025DA20 44051000 */  mfc1  $a1, $f2
/* 18C304 8025DA24 3C013FC0 */  lui   $at, 0x3fc0
/* 18C308 8025DA28 44811000 */  mtc1  $at, $f2
/* 18C30C 8025DA2C 00000000 */  nop   
/* 18C310 8025DA30 46024200 */  add.s $f8, $f8, $f2
/* 18C314 8025DA34 44073000 */  mfc1  $a3, $f6
/* 18C318 8025DA38 44064000 */  mfc1  $a2, $f8
/* 18C31C 8025DA3C 0000202D */  daddu $a0, $zero, $zero
/* 18C320 8025DA40 E7B40010 */  swc1  $f20, 0x10($sp)
/* 18C324 8025DA44 0C01BECC */  jal   fx_walk_normal
/* 18C328 8025DA48 E7A00014 */   swc1  $f0, 0x14($sp)
.L8025DA4C:
.L8025DA4C:
/* 18C32C 8025DA4C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 18C330 8025DA50 8FB00018 */  lw    $s0, 0x18($sp)
/* 18C334 8025DA54 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 18C338 8025DA58 03E00008 */  jr    $ra
/* 18C33C 8025DA5C 27BD0028 */   addiu $sp, $sp, 0x28

