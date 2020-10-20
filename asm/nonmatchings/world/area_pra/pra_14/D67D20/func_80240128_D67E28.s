.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240128_D67E28
/* D67E28 80240128 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D67E2C 8024012C AFB00040 */  sw        $s0, 0x40($sp)
/* D67E30 80240130 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D67E34 80240134 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D67E38 80240138 AFB20048 */  sw        $s2, 0x48($sp)
/* D67E3C 8024013C AFBF004C */  sw        $ra, 0x4c($sp)
/* D67E40 80240140 AFB10044 */  sw        $s1, 0x44($sp)
/* D67E44 80240144 8E020000 */  lw        $v0, ($s0)
/* D67E48 80240148 821100BE */  lb        $s1, 0xbe($s0)
/* D67E4C 8024014C 30420001 */  andi      $v0, $v0, 1
/* D67E50 80240150 10400061 */  beqz      $v0, .L802402D8
/* D67E54 80240154 27B20020 */   addiu    $s2, $sp, 0x20
/* D67E58 80240158 8E0400CC */  lw        $a0, 0xcc($s0)
/* D67E5C 8024015C 0C044181 */  jal       get_shadow_by_index
/* D67E60 80240160 00000000 */   nop      
/* D67E64 80240164 0C048B77 */  jal       func_80122DDC
/* D67E68 80240168 84440008 */   lh       $a0, 8($v0)
/* D67E6C 8024016C 8C430000 */  lw        $v1, ($v0)
/* D67E70 80240170 34630200 */  ori       $v1, $v1, 0x200
/* D67E74 80240174 AC430000 */  sw        $v1, ($v0)
/* D67E78 80240178 8E050028 */  lw        $a1, 0x28($s0)
/* D67E7C 8024017C 8E06002C */  lw        $a2, 0x2c($s0)
/* D67E80 80240180 27A20030 */  addiu     $v0, $sp, 0x30
/* D67E84 80240184 AFA20010 */  sw        $v0, 0x10($sp)
/* D67E88 80240188 27A20034 */  addiu     $v0, $sp, 0x34
/* D67E8C 8024018C AFA20014 */  sw        $v0, 0x14($sp)
/* D67E90 80240190 C6000030 */  lwc1      $f0, 0x30($s0)
/* D67E94 80240194 3C04800A */  lui       $a0, 0x800a
/* D67E98 80240198 8484A634 */  lh        $a0, -0x59cc($a0)
/* D67E9C 8024019C 46000007 */  neg.s     $f0, $f0
/* D67EA0 802401A0 44070000 */  mfc1      $a3, $f0
/* D67EA4 802401A4 27A20038 */  addiu     $v0, $sp, 0x38
/* D67EA8 802401A8 0C00B94E */  jal       get_screen_coords
/* D67EAC 802401AC AFA20018 */   sw       $v0, 0x18($sp)
/* D67EB0 802401B0 8E0400A4 */  lw        $a0, 0xa4($s0)
/* D67EB4 802401B4 0C090008 */  jal       func_80240020
/* D67EB8 802401B8 00000000 */   nop      
/* D67EBC 802401BC C6020080 */  lwc1      $f2, 0x80($s0)
/* D67EC0 802401C0 3C014307 */  lui       $at, 0x4307
/* D67EC4 802401C4 44810000 */  mtc1      $at, $f0
/* D67EC8 802401C8 00000000 */  nop       
/* D67ECC 802401CC 4602003C */  c.lt.s    $f0, $f2
/* D67ED0 802401D0 00000000 */  nop       
/* D67ED4 802401D4 4500000B */  bc1f      .L80240204
/* D67ED8 802401D8 24040002 */   addiu    $a0, $zero, 2
/* D67EDC 802401DC 3C014361 */  lui       $at, 0x4361
/* D67EE0 802401E0 44810000 */  mtc1      $at, $f0
/* D67EE4 802401E4 00000000 */  nop       
/* D67EE8 802401E8 4600103C */  c.lt.s    $f2, $f0
/* D67EEC 802401EC 00000000 */  nop       
/* D67EF0 802401F0 45000004 */  bc1f      .L80240204
/* D67EF4 802401F4 00000000 */   nop      
/* D67EF8 802401F8 0C090015 */  jal       func_80240054
/* D67EFC 802401FC 0040202D */   daddu    $a0, $v0, $zero
/* D67F00 80240200 24040002 */  addiu     $a0, $zero, 2
.L80240204:
/* D67F04 80240204 3C063F80 */  lui       $a2, 0x3f80
/* D67F08 80240208 0C0B76A3 */  jal       func_802DDA8C
/* D67F0C 8024020C 0040282D */   daddu    $a1, $v0, $zero
/* D67F10 80240210 8E020000 */  lw        $v0, ($s0)
/* D67F14 80240214 3C030002 */  lui       $v1, 2
/* D67F18 80240218 00431024 */  and       $v0, $v0, $v1
/* D67F1C 8024021C 54400022 */  bnel      $v0, $zero, .L802402A8
/* D67F20 80240220 24110011 */   addiu    $s1, $zero, 0x11
/* D67F24 80240224 9203000E */  lbu       $v1, 0xe($s0)
/* D67F28 80240228 3C02802E */  lui       $v0, 0x802e
/* D67F2C 8024022C 90429D70 */  lbu       $v0, -0x6290($v0)
/* D67F30 80240230 10620018 */  beq       $v1, $v0, .L80240294
/* D67F34 80240234 2C6200FE */   sltiu    $v0, $v1, 0xfe
/* D67F38 80240238 1040000B */  beqz      $v0, .L80240268
/* D67F3C 8024023C 24110011 */   addiu    $s1, $zero, 0x11
/* D67F40 80240240 24040002 */  addiu     $a0, $zero, 2
/* D67F44 80240244 2405FFFF */  addiu     $a1, $zero, -1
/* D67F48 80240248 24060007 */  addiu     $a2, $zero, 7
/* D67F4C 8024024C 0060102D */  daddu     $v0, $v1, $zero
/* D67F50 80240250 0000382D */  daddu     $a3, $zero, $zero
/* D67F54 80240254 AFA00010 */  sw        $zero, 0x10($sp)
/* D67F58 80240258 AFA00014 */  sw        $zero, 0x14($sp)
/* D67F5C 8024025C AFA0001C */  sw        $zero, 0x1c($sp)
/* D67F60 80240260 080900A3 */  j         .L8024028C
/* D67F64 80240264 AFA20018 */   sw       $v0, 0x18($sp)
.L80240268:
/* D67F68 80240268 2411000D */  addiu     $s1, $zero, 0xd
/* D67F6C 8024026C 24040002 */  addiu     $a0, $zero, 2
/* D67F70 80240270 2405FFFF */  addiu     $a1, $zero, -1
/* D67F74 80240274 0000302D */  daddu     $a2, $zero, $zero
/* D67F78 80240278 00C0382D */  daddu     $a3, $a2, $zero
/* D67F7C 8024027C AFA00010 */  sw        $zero, 0x10($sp)
/* D67F80 80240280 AFA00014 */  sw        $zero, 0x14($sp)
/* D67F84 80240284 AFA00018 */  sw        $zero, 0x18($sp)
/* D67F88 80240288 AFA0001C */  sw        $zero, 0x1c($sp)
.L8024028C:
/* D67F8C 8024028C 0C0B77B9 */  jal       func_802DDEE4
/* D67F90 80240290 00000000 */   nop      
.L80240294:
/* D67F94 80240294 9202000E */  lbu       $v0, 0xe($s0)
/* D67F98 80240298 3C01802E */  lui       $at, 0x802e
/* D67F9C 8024029C A0229D70 */  sb        $v0, -0x6290($at)
/* D67FA0 802402A0 080900AD */  j         .L802402B4
/* D67FA4 802402A4 0240202D */   daddu    $a0, $s2, $zero
.L802402A8:
/* D67FA8 802402A8 3C01802E */  lui       $at, 0x802e
/* D67FAC 802402AC A0209D70 */  sb        $zero, -0x6290($at)
/* D67FB0 802402B0 0240202D */  daddu     $a0, $s2, $zero
.L802402B4:
/* D67FB4 802402B4 AC910000 */  sw        $s1, ($a0)
/* D67FB8 802402B8 AC900008 */  sw        $s0, 8($a0)
/* D67FBC 802402BC 8FA20038 */  lw        $v0, 0x38($sp)
/* D67FC0 802402C0 3C038024 */  lui       $v1, 0x8024
/* D67FC4 802402C4 246302F0 */  addiu     $v1, $v1, 0x2f0
/* D67FC8 802402C8 AC83000C */  sw        $v1, 0xc($a0)
/* D67FCC 802402CC 00021023 */  negu      $v0, $v0
/* D67FD0 802402D0 0C047644 */  jal       queue_render_task
/* D67FD4 802402D4 AC820004 */   sw       $v0, 4($a0)
.L802402D8:
/* D67FD8 802402D8 8FBF004C */  lw        $ra, 0x4c($sp)
/* D67FDC 802402DC 8FB20048 */  lw        $s2, 0x48($sp)
/* D67FE0 802402E0 8FB10044 */  lw        $s1, 0x44($sp)
/* D67FE4 802402E4 8FB00040 */  lw        $s0, 0x40($sp)
/* D67FE8 802402E8 03E00008 */  jr        $ra
/* D67FEC 802402EC 27BD0050 */   addiu    $sp, $sp, 0x50
