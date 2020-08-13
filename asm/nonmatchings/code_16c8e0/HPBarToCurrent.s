.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel HPBarToCurrent
/* 19C088 8026D7A8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C08C 8026D7AC AFB00010 */  sw    $s0, 0x10($sp)
/* 19C090 8026D7B0 0080802D */  daddu $s0, $a0, $zero
/* 19C094 8026D7B4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19C098 8026D7B8 8E02000C */  lw    $v0, 0xc($s0)
/* 19C09C 8026D7BC 0C0B1EAF */  jal   get_variable
/* 19C0A0 8026D7C0 8C450000 */   lw    $a1, ($v0)
/* 19C0A4 8026D7C4 0040202D */  daddu $a0, $v0, $zero
/* 19C0A8 8026D7C8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C0AC 8026D7CC 14820002 */  bne   $a0, $v0, .L8026D7D8
/* 19C0B0 8026D7D0 00000000 */   nop   
/* 19C0B4 8026D7D4 8E040148 */  lw    $a0, 0x148($s0)
.L8026D7D8:
/* 19C0B8 8026D7D8 0C09A75B */  jal   get_actor
/* 19C0BC 8026D7DC 00000000 */   nop   
/* 19C0C0 8026D7E0 0040282D */  daddu $a1, $v0, $zero
/* 19C0C4 8026D7E4 8CA20008 */  lw    $v0, 8($a1)
/* 19C0C8 8026D7E8 80420022 */  lb    $v0, 0x22($v0)
/* 19C0CC 8026D7EC C4A00144 */  lwc1  $f0, 0x144($a1)
/* 19C0D0 8026D7F0 44821000 */  mtc1  $v0, $f2
/* 19C0D4 8026D7F4 00000000 */  nop   
/* 19C0D8 8026D7F8 468010A0 */  cvt.s.w $f2, $f2
/* 19C0DC 8026D7FC 46020000 */  add.s $f0, $f0, $f2
/* 19C0E0 8026D800 8CA30008 */  lw    $v1, 8($a1)
/* 19C0E4 8026D804 C4A2014C */  lwc1  $f2, 0x14c($a1)
/* 19C0E8 8026D808 4600018D */  trunc.w.s $f6, $f0
/* 19C0EC 8026D80C 44023000 */  mfc1  $v0, $f6
/* 19C0F0 8026D810 00000000 */  nop   
/* 19C0F4 8026D814 A4A20156 */  sh    $v0, 0x156($a1)
/* 19C0F8 8026D818 80620023 */  lb    $v0, 0x23($v1)
/* 19C0FC 8026D81C C4A00148 */  lwc1  $f0, 0x148($a1)
/* 19C100 8026D820 44822000 */  mtc1  $v0, $f4
/* 19C104 8026D824 00000000 */  nop   
/* 19C108 8026D828 46802120 */  cvt.s.w $f4, $f4
/* 19C10C 8026D82C 4600118D */  trunc.w.s $f6, $f2
/* 19C110 8026D830 44023000 */  mfc1  $v0, $f6
/* 19C114 8026D834 46040000 */  add.s $f0, $f0, $f4
/* 19C118 8026D838 A4A2015A */  sh    $v0, 0x15a($a1)
/* 19C11C 8026D83C 8CA20000 */  lw    $v0, ($a1)
/* 19C120 8026D840 30420800 */  andi  $v0, $v0, 0x800
/* 19C124 8026D844 4600018D */  trunc.w.s $f6, $f0
/* 19C128 8026D848 44033000 */  mfc1  $v1, $f6
/* 19C12C 8026D84C 10400011 */  beqz  $v0, .L8026D894
/* 19C130 8026D850 A4A30158 */   sh    $v1, 0x158($a1)
/* 19C134 8026D854 90A20191 */  lbu   $v0, 0x191($a1)
/* 19C138 8026D858 C4A00148 */  lwc1  $f0, 0x148($a1)
/* 19C13C 8026D85C 44821000 */  mtc1  $v0, $f2
/* 19C140 8026D860 00000000 */  nop   
/* 19C144 8026D864 468010A0 */  cvt.s.w $f2, $f2
/* 19C148 8026D868 8CA20008 */  lw    $v0, 8($a1)
/* 19C14C 8026D86C 46020001 */  sub.s $f0, $f0, $f2
/* 19C150 8026D870 80420023 */  lb    $v0, 0x23($v0)
/* 19C154 8026D874 44821000 */  mtc1  $v0, $f2
/* 19C158 8026D878 00000000 */  nop   
/* 19C15C 8026D87C 468010A0 */  cvt.s.w $f2, $f2
/* 19C160 8026D880 46020001 */  sub.s $f0, $f0, $f2
/* 19C164 8026D884 4600018D */  trunc.w.s $f6, $f0
/* 19C168 8026D888 44023000 */  mfc1  $v0, $f6
/* 19C16C 8026D88C 00000000 */  nop   
/* 19C170 8026D890 A4A20158 */  sh    $v0, 0x158($a1)
.L8026D894:
/* 19C174 8026D894 80A201B8 */  lb    $v0, 0x1b8($a1)
/* 19C178 8026D898 80A401B9 */  lb    $a0, 0x1b9($a1)
/* 19C17C 8026D89C 00021840 */  sll   $v1, $v0, 1
/* 19C180 8026D8A0 00621821 */  addu  $v1, $v1, $v0
/* 19C184 8026D8A4 000318C0 */  sll   $v1, $v1, 3
/* 19C188 8026D8A8 00621821 */  addu  $v1, $v1, $v0
/* 19C18C 8026D8AC 14800002 */  bnez  $a0, .L8026D8B8
/* 19C190 8026D8B0 0064001A */   div   $zero, $v1, $a0
/* 19C194 8026D8B4 0007000D */  break 7
.L8026D8B8:
/* 19C198 8026D8B8 2401FFFF */  addiu $at, $zero, -1
/* 19C19C 8026D8BC 14810004 */  bne   $a0, $at, .L8026D8D0
/* 19C1A0 8026D8C0 3C018000 */   lui   $at, 0x8000
/* 19C1A4 8026D8C4 14610002 */  bne   $v1, $at, .L8026D8D0
/* 19C1A8 8026D8C8 00000000 */   nop   
/* 19C1AC 8026D8CC 0006000D */  break 6
.L8026D8D0:
/* 19C1B0 8026D8D0 00001812 */  mflo  $v1
/* 19C1B4 8026D8D4 A0A301BC */  sb    $v1, 0x1bc($a1)
/* 19C1B8 8026D8D8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19C1BC 8026D8DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C1C0 8026D8E0 24020002 */  addiu $v0, $zero, 2
/* 19C1C4 8026D8E4 03E00008 */  jr    $ra
/* 19C1C8 8026D8E8 27BD0018 */   addiu $sp, $sp, 0x18

/* 19C1CC 8026D8EC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19C1D0 8026D8F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C1D4 8026D8F4 0080802D */  daddu $s0, $a0, $zero
/* 19C1D8 8026D8F8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 19C1DC 8026D8FC 8E02000C */  lw    $v0, 0xc($s0)
/* 19C1E0 8026D900 0C0B1EAF */  jal   get_variable
/* 19C1E4 8026D904 8C450000 */   lw    $a1, ($v0)
/* 19C1E8 8026D908 0040202D */  daddu $a0, $v0, $zero
/* 19C1EC 8026D90C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C1F0 8026D910 14820002 */  bne   $a0, $v0, .L8026D91C
/* 19C1F4 8026D914 00000000 */   nop   
/* 19C1F8 8026D918 8E040148 */  lw    $a0, 0x148($s0)
.L8026D91C:
/* 19C1FC 8026D91C 0C09A75B */  jal   get_actor
/* 19C200 8026D920 00000000 */   nop   
/* 19C204 8026D924 0C099ABE */  jal   func_80266AF8
/* 19C208 8026D928 0040202D */   daddu $a0, $v0, $zero
/* 19C20C 8026D92C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 19C210 8026D930 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C214 8026D934 24020002 */  addiu $v0, $zero, 2
/* 19C218 8026D938 03E00008 */  jr    $ra
/* 19C21C 8026D93C 27BD0018 */   addiu $sp, $sp, 0x18

/* 19C220 8026D940 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19C224 8026D944 AFB10014 */  sw    $s1, 0x14($sp)
/* 19C228 8026D948 0080882D */  daddu $s1, $a0, $zero
/* 19C22C 8026D94C AFBF001C */  sw    $ra, 0x1c($sp)
/* 19C230 8026D950 AFB20018 */  sw    $s2, 0x18($sp)
/* 19C234 8026D954 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C238 8026D958 8E30000C */  lw    $s0, 0xc($s1)
/* 19C23C 8026D95C 8E050000 */  lw    $a1, ($s0)
/* 19C240 8026D960 0C0B1EAF */  jal   get_variable
/* 19C244 8026D964 26100004 */   addiu $s0, $s0, 4
/* 19C248 8026D968 0040902D */  daddu $s2, $v0, $zero
/* 19C24C 8026D96C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C250 8026D970 16420002 */  bne   $s2, $v0, .L8026D97C
/* 19C254 8026D974 00000000 */   nop   
/* 19C258 8026D978 8E320148 */  lw    $s2, 0x148($s1)
.L8026D97C:
/* 19C25C 8026D97C 8E050000 */  lw    $a1, ($s0)
/* 19C260 8026D980 26100004 */  addiu $s0, $s0, 4
/* 19C264 8026D984 0C0B1EAF */  jal   get_variable
/* 19C268 8026D988 0220202D */   daddu $a0, $s1, $zero
/* 19C26C 8026D98C 0220202D */  daddu $a0, $s1, $zero
/* 19C270 8026D990 8E050000 */  lw    $a1, ($s0)
/* 19C274 8026D994 0C0B1EAF */  jal   get_variable
/* 19C278 8026D998 0040882D */   daddu $s1, $v0, $zero
/* 19C27C 8026D99C 0240202D */  daddu $a0, $s2, $zero
/* 19C280 8026D9A0 0C09A75B */  jal   get_actor
/* 19C284 8026D9A4 0040802D */   daddu $s0, $v0, $zero
/* 19C288 8026D9A8 0040202D */  daddu $a0, $v0, $zero
/* 19C28C 8026D9AC 8C820008 */  lw    $v0, 8($a0)
/* 19C290 8026D9B0 A0910198 */  sb    $s1, 0x198($a0)
/* 19C294 8026D9B4 A0900199 */  sb    $s0, 0x199($a0)
/* 19C298 8026D9B8 80420022 */  lb    $v0, 0x22($v0)
/* 19C29C 8026D9BC C4820138 */  lwc1  $f2, 0x138($a0)
/* 19C2A0 8026D9C0 44820000 */  mtc1  $v0, $f0
/* 19C2A4 8026D9C4 00000000 */  nop   
/* 19C2A8 8026D9C8 46800020 */  cvt.s.w $f0, $f0
/* 19C2AC 8026D9CC 46001080 */  add.s $f2, $f2, $f0
/* 19C2B0 8026D9D0 80820198 */  lb    $v0, 0x198($a0)
/* 19C2B4 8026D9D4 44820000 */  mtc1  $v0, $f0
/* 19C2B8 8026D9D8 00000000 */  nop   
/* 19C2BC 8026D9DC 46800020 */  cvt.s.w $f0, $f0
/* 19C2C0 8026D9E0 46001080 */  add.s $f2, $f2, $f0
/* 19C2C4 8026D9E4 8C830008 */  lw    $v1, 8($a0)
/* 19C2C8 8026D9E8 4600118D */  trunc.w.s $f6, $f2
/* 19C2CC 8026D9EC 44023000 */  mfc1  $v0, $f6
/* 19C2D0 8026D9F0 00000000 */  nop   
/* 19C2D4 8026D9F4 A4820156 */  sh    $v0, 0x156($a0)
/* 19C2D8 8026D9F8 80620023 */  lb    $v0, 0x23($v1)
/* 19C2DC 8026D9FC C482013C */  lwc1  $f2, 0x13c($a0)
/* 19C2E0 8026DA00 44820000 */  mtc1  $v0, $f0
/* 19C2E4 8026DA04 00000000 */  nop   
/* 19C2E8 8026DA08 46800020 */  cvt.s.w $f0, $f0
/* 19C2EC 8026DA0C 46001080 */  add.s $f2, $f2, $f0
/* 19C2F0 8026DA10 80820199 */  lb    $v0, 0x199($a0)
/* 19C2F4 8026DA14 C4800140 */  lwc1  $f0, 0x140($a0)
/* 19C2F8 8026DA18 44822000 */  mtc1  $v0, $f4
/* 19C2FC 8026DA1C 00000000 */  nop   
/* 19C300 8026DA20 46802120 */  cvt.s.w $f4, $f4
/* 19C304 8026DA24 4600018D */  trunc.w.s $f6, $f0
/* 19C308 8026DA28 44023000 */  mfc1  $v0, $f6
/* 19C30C 8026DA2C 00000000 */  nop   
/* 19C310 8026DA30 A482015A */  sh    $v0, 0x15a($a0)
/* 19C314 8026DA34 8C820000 */  lw    $v0, ($a0)
/* 19C318 8026DA38 46041080 */  add.s $f2, $f2, $f4
/* 19C31C 8026DA3C 30420800 */  andi  $v0, $v0, 0x800
/* 19C320 8026DA40 4600118D */  trunc.w.s $f6, $f2
/* 19C324 8026DA44 44033000 */  mfc1  $v1, $f6
/* 19C328 8026DA48 1040000B */  beqz  $v0, .L8026DA78
/* 19C32C 8026DA4C A4830158 */   sh    $v1, 0x158($a0)
/* 19C330 8026DA50 90820191 */  lbu   $v0, 0x191($a0)
/* 19C334 8026DA54 C480013C */  lwc1  $f0, 0x13c($a0)
/* 19C338 8026DA58 44821000 */  mtc1  $v0, $f2
/* 19C33C 8026DA5C 00000000 */  nop   
/* 19C340 8026DA60 468010A0 */  cvt.s.w $f2, $f2
/* 19C344 8026DA64 46020001 */  sub.s $f0, $f0, $f2
/* 19C348 8026DA68 4600018D */  trunc.w.s $f6, $f0
/* 19C34C 8026DA6C 44023000 */  mfc1  $v0, $f6
/* 19C350 8026DA70 00000000 */  nop   
/* 19C354 8026DA74 A4820158 */  sh    $v0, 0x158($a0)
.L8026DA78:
/* 19C358 8026DA78 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19C35C 8026DA7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C360 8026DA80 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C364 8026DA84 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C368 8026DA88 24020002 */  addiu $v0, $zero, 2
/* 19C36C 8026DA8C 03E00008 */  jr    $ra
/* 19C370 8026DA90 27BD0020 */   addiu $sp, $sp, 0x20

/* 19C374 8026DA94 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19C378 8026DA98 AFB10014 */  sw    $s1, 0x14($sp)
/* 19C37C 8026DA9C 0080882D */  daddu $s1, $a0, $zero
/* 19C380 8026DAA0 AFBF0024 */  sw    $ra, 0x24($sp)
/* 19C384 8026DAA4 AFB40020 */  sw    $s4, 0x20($sp)
/* 19C388 8026DAA8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19C38C 8026DAAC AFB20018 */  sw    $s2, 0x18($sp)
/* 19C390 8026DAB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19C394 8026DAB4 8E30000C */  lw    $s0, 0xc($s1)
/* 19C398 8026DAB8 8E050000 */  lw    $a1, ($s0)
/* 19C39C 8026DABC 0C0B1EAF */  jal   get_variable
/* 19C3A0 8026DAC0 26100004 */   addiu $s0, $s0, 4
/* 19C3A4 8026DAC4 0040A02D */  daddu $s4, $v0, $zero
/* 19C3A8 8026DAC8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19C3AC 8026DACC 16820002 */  bne   $s4, $v0, .L8026DAD8
/* 19C3B0 8026DAD0 00000000 */   nop   
/* 19C3B4 8026DAD4 8E340148 */  lw    $s4, 0x148($s1)
.L8026DAD8:
/* 19C3B8 8026DAD8 8E050000 */  lw    $a1, ($s0)
/* 19C3BC 8026DADC 26100004 */  addiu $s0, $s0, 4
/* 19C3C0 8026DAE0 0C0B1EAF */  jal   get_variable
/* 19C3C4 8026DAE4 0220202D */   daddu $a0, $s1, $zero
/* 19C3C8 8026DAE8 8E050000 */  lw    $a1, ($s0)
/* 19C3CC 8026DAEC 26100004 */  addiu $s0, $s0, 4
/* 19C3D0 8026DAF0 0220202D */  daddu $a0, $s1, $zero
/* 19C3D4 8026DAF4 0C0B1EAF */  jal   get_variable
/* 19C3D8 8026DAF8 0040982D */   daddu $s3, $v0, $zero
/* 19C3DC 8026DAFC 8E050000 */  lw    $a1, ($s0)
/* 19C3E0 8026DB00 26100004 */  addiu $s0, $s0, 4
/* 19C3E4 8026DB04 0220202D */  daddu $a0, $s1, $zero
/* 19C3E8 8026DB08 0C0B1EAF */  jal   get_variable
/* 19C3EC 8026DB0C 0040902D */   daddu $s2, $v0, $zero
/* 19C3F0 8026DB10 0220202D */  daddu $a0, $s1, $zero
/* 19C3F4 8026DB14 8E050000 */  lw    $a1, ($s0)
/* 19C3F8 8026DB18 0C0B1EAF */  jal   get_variable
/* 19C3FC 8026DB1C 0040882D */   daddu $s1, $v0, $zero
/* 19C400 8026DB20 0280202D */  daddu $a0, $s4, $zero
/* 19C404 8026DB24 0C09A75B */  jal   get_actor
/* 19C408 8026DB28 0040802D */   daddu $s0, $v0, $zero
/* 19C40C 8026DB2C 0040182D */  daddu $v1, $v0, $zero
/* 19C410 8026DB30 A0730194 */  sb    $s3, 0x194($v1)
/* 19C414 8026DB34 A0720195 */  sb    $s2, 0x195($v1)
/* 19C418 8026DB38 A0710196 */  sb    $s1, 0x196($v1)
/* 19C41C 8026DB3C A0700197 */  sb    $s0, 0x197($v1)
/* 19C420 8026DB40 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19C424 8026DB44 8FB40020 */  lw    $s4, 0x20($sp)
/* 19C428 8026DB48 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19C42C 8026DB4C 8FB20018 */  lw    $s2, 0x18($sp)
/* 19C430 8026DB50 8FB10014 */  lw    $s1, 0x14($sp)
/* 19C434 8026DB54 8FB00010 */  lw    $s0, 0x10($sp)
/* 19C438 8026DB58 24020002 */  addiu $v0, $zero, 2
/* 19C43C 8026DB5C 03E00008 */  jr    $ra
/* 19C440 8026DB60 27BD0028 */   addiu $sp, $sp, 0x28

