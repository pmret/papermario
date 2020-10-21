.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240158_D62E68
/* D62E68 80240158 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D62E6C 8024015C AFB00040 */  sw        $s0, 0x40($sp)
/* D62E70 80240160 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D62E74 80240164 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D62E78 80240168 AFB20048 */  sw        $s2, 0x48($sp)
/* D62E7C 8024016C AFBF004C */  sw        $ra, 0x4c($sp)
/* D62E80 80240170 AFB10044 */  sw        $s1, 0x44($sp)
/* D62E84 80240174 8E020000 */  lw        $v0, ($s0)
/* D62E88 80240178 821100BE */  lb        $s1, 0xbe($s0)
/* D62E8C 8024017C 30420001 */  andi      $v0, $v0, 1
/* D62E90 80240180 10400061 */  beqz      $v0, .L80240308
/* D62E94 80240184 27B20020 */   addiu    $s2, $sp, 0x20
/* D62E98 80240188 8E0400CC */  lw        $a0, 0xcc($s0)
/* D62E9C 8024018C 0C044181 */  jal       get_shadow_by_index
/* D62EA0 80240190 00000000 */   nop      
/* D62EA4 80240194 0C048B77 */  jal       func_80122DDC
/* D62EA8 80240198 84440008 */   lh       $a0, 8($v0)
/* D62EAC 8024019C 8C430000 */  lw        $v1, ($v0)
/* D62EB0 802401A0 34630200 */  ori       $v1, $v1, 0x200
/* D62EB4 802401A4 AC430000 */  sw        $v1, ($v0)
/* D62EB8 802401A8 8E050028 */  lw        $a1, 0x28($s0)
/* D62EBC 802401AC 8E06002C */  lw        $a2, 0x2c($s0)
/* D62EC0 802401B0 27A20030 */  addiu     $v0, $sp, 0x30
/* D62EC4 802401B4 AFA20010 */  sw        $v0, 0x10($sp)
/* D62EC8 802401B8 27A20034 */  addiu     $v0, $sp, 0x34
/* D62ECC 802401BC AFA20014 */  sw        $v0, 0x14($sp)
/* D62ED0 802401C0 C6000030 */  lwc1      $f0, 0x30($s0)
/* D62ED4 802401C4 3C04800A */  lui       $a0, 0x800a
/* D62ED8 802401C8 8484A634 */  lh        $a0, -0x59cc($a0)
/* D62EDC 802401CC 46000007 */  neg.s     $f0, $f0
/* D62EE0 802401D0 44070000 */  mfc1      $a3, $f0
/* D62EE4 802401D4 27A20038 */  addiu     $v0, $sp, 0x38
/* D62EE8 802401D8 0C00B94E */  jal       get_screen_coords
/* D62EEC 802401DC AFA20018 */   sw       $v0, 0x18($sp)
/* D62EF0 802401E0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D62EF4 802401E4 0C090014 */  jal       func_80240050_D62D60
/* D62EF8 802401E8 00000000 */   nop      
/* D62EFC 802401EC C6020080 */  lwc1      $f2, 0x80($s0)
/* D62F00 802401F0 3C014307 */  lui       $at, 0x4307
/* D62F04 802401F4 44810000 */  mtc1      $at, $f0
/* D62F08 802401F8 00000000 */  nop       
/* D62F0C 802401FC 4602003C */  c.lt.s    $f0, $f2
/* D62F10 80240200 00000000 */  nop       
/* D62F14 80240204 4500000B */  bc1f      .L80240234
/* D62F18 80240208 24040002 */   addiu    $a0, $zero, 2
/* D62F1C 8024020C 3C014361 */  lui       $at, 0x4361
/* D62F20 80240210 44810000 */  mtc1      $at, $f0
/* D62F24 80240214 00000000 */  nop       
/* D62F28 80240218 4600103C */  c.lt.s    $f2, $f0
/* D62F2C 8024021C 00000000 */  nop       
/* D62F30 80240220 45000004 */  bc1f      .L80240234
/* D62F34 80240224 00000000 */   nop      
/* D62F38 80240228 0C090021 */  jal       func_80240084_D62D94
/* D62F3C 8024022C 0040202D */   daddu    $a0, $v0, $zero
/* D62F40 80240230 24040002 */  addiu     $a0, $zero, 2
.L80240234:
/* D62F44 80240234 3C063F80 */  lui       $a2, 0x3f80
/* D62F48 80240238 0C0B76A3 */  jal       func_802DDA8C
/* D62F4C 8024023C 0040282D */   daddu    $a1, $v0, $zero
/* D62F50 80240240 8E020000 */  lw        $v0, ($s0)
/* D62F54 80240244 3C030002 */  lui       $v1, 2
/* D62F58 80240248 00431024 */  and       $v0, $v0, $v1
/* D62F5C 8024024C 54400022 */  bnel      $v0, $zero, .L802402D8
/* D62F60 80240250 24110011 */   addiu    $s1, $zero, 0x11
/* D62F64 80240254 9203000E */  lbu       $v1, 0xe($s0)
/* D62F68 80240258 3C02802E */  lui       $v0, 0x802e
/* D62F6C 8024025C 90429D70 */  lbu       $v0, -0x6290($v0)
/* D62F70 80240260 10620018 */  beq       $v1, $v0, .L802402C4
/* D62F74 80240264 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D62F78 80240268 1040000B */  beqz      $v0, .L80240298
/* D62F7C 8024026C 24110011 */   addiu    $s1, $zero, 0x11
/* D62F80 80240270 24040002 */  addiu     $a0, $zero, 2
/* D62F84 80240274 2405FFFF */  addiu     $a1, $zero, -1
/* D62F88 80240278 24060007 */  addiu     $a2, $zero, 7
/* D62F8C 8024027C 0060102D */  daddu     $v0, $v1, $zero
/* D62F90 80240280 0000382D */  daddu     $a3, $zero, $zero
/* D62F94 80240284 AFA00010 */  sw        $zero, 0x10($sp)
/* D62F98 80240288 AFA00014 */  sw        $zero, 0x14($sp)
/* D62F9C 8024028C AFA0001C */  sw        $zero, 0x1c($sp)
/* D62FA0 80240290 080900AF */  j         .L802402BC
/* D62FA4 80240294 AFA20018 */   sw       $v0, 0x18($sp)
.L80240298:
/* D62FA8 80240298 2411000D */  addiu     $s1, $zero, 0xd
/* D62FAC 8024029C 24040002 */  addiu     $a0, $zero, 2
/* D62FB0 802402A0 2405FFFF */  addiu     $a1, $zero, -1
/* D62FB4 802402A4 0000302D */  daddu     $a2, $zero, $zero
/* D62FB8 802402A8 00C0382D */  daddu     $a3, $a2, $zero
/* D62FBC 802402AC AFA00010 */  sw        $zero, 0x10($sp)
/* D62FC0 802402B0 AFA00014 */  sw        $zero, 0x14($sp)
/* D62FC4 802402B4 AFA00018 */  sw        $zero, 0x18($sp)
/* D62FC8 802402B8 AFA0001C */  sw        $zero, 0x1c($sp)
.L802402BC:
/* D62FCC 802402BC 0C0B77B9 */  jal       func_802DDEE4
/* D62FD0 802402C0 00000000 */   nop      
.L802402C4:
/* D62FD4 802402C4 9202000E */  lbu       $v0, 0xe($s0)
/* D62FD8 802402C8 3C01802E */  lui       $at, 0x802e
/* D62FDC 802402CC A0229D70 */  sb        $v0, -0x6290($at)
/* D62FE0 802402D0 080900B9 */  j         .L802402E4
/* D62FE4 802402D4 0240202D */   daddu    $a0, $s2, $zero
.L802402D8:
/* D62FE8 802402D8 3C01802E */  lui       $at, 0x802e
/* D62FEC 802402DC A0209D70 */  sb        $zero, -0x6290($at)
/* D62FF0 802402E0 0240202D */  daddu     $a0, $s2, $zero
.L802402E4:
/* D62FF4 802402E4 AC910000 */  sw        $s1, ($a0)
/* D62FF8 802402E8 AC900008 */  sw        $s0, 8($a0)
/* D62FFC 802402EC 8FA20038 */  lw        $v0, 0x38($sp)
/* D63000 802402F0 3C038024 */  lui       $v1, 0x8024
/* D63004 802402F4 24630320 */  addiu     $v1, $v1, 0x320
/* D63008 802402F8 AC83000C */  sw        $v1, 0xc($a0)
/* D6300C 802402FC 00021023 */  negu      $v0, $v0
/* D63010 80240300 0C047644 */  jal       queue_render_task
/* D63014 80240304 AC820004 */   sw       $v0, 4($a0)
.L80240308:
/* D63018 80240308 8FBF004C */  lw        $ra, 0x4c($sp)
/* D6301C 8024030C 8FB20048 */  lw        $s2, 0x48($sp)
/* D63020 80240310 8FB10044 */  lw        $s1, 0x44($sp)
/* D63024 80240314 8FB00040 */  lw        $s0, 0x40($sp)
/* D63028 80240318 03E00008 */  jr        $ra
/* D6302C 8024031C 27BD0050 */   addiu    $sp, $sp, 0x50
