.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024019C_BBB51C
/* BBB51C 8024019C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBB520 802401A0 AFB10014 */  sw        $s1, 0x14($sp)
/* BBB524 802401A4 0080882D */  daddu     $s1, $a0, $zero
/* BBB528 802401A8 AFB20018 */  sw        $s2, 0x18($sp)
/* BBB52C 802401AC AFBF001C */  sw        $ra, 0x1c($sp)
/* BBB530 802401B0 AFB00010 */  sw        $s0, 0x10($sp)
/* BBB534 802401B4 8E30000C */  lw        $s0, 0xc($s1)
/* BBB538 802401B8 10A0000E */  beqz      $a1, .L802401F4
/* BBB53C 802401BC 0000902D */   daddu    $s2, $zero, $zero
/* BBB540 802401C0 8E050000 */  lw        $a1, ($s0)
/* BBB544 802401C4 0C0B1EAF */  jal       get_variable
/* BBB548 802401C8 26100004 */   addiu    $s0, $s0, 4
/* BBB54C 802401CC AE220074 */  sw        $v0, 0x74($s1)
/* BBB550 802401D0 8E050000 */  lw        $a1, ($s0)
/* BBB554 802401D4 26100004 */  addiu     $s0, $s0, 4
/* BBB558 802401D8 0C0B1EAF */  jal       get_variable
/* BBB55C 802401DC 0220202D */   daddu    $a0, $s1, $zero
/* BBB560 802401E0 AE220078 */  sw        $v0, 0x78($s1)
/* BBB564 802401E4 8E050000 */  lw        $a1, ($s0)
/* BBB568 802401E8 0C0B1EAF */  jal       get_variable
/* BBB56C 802401EC 0220202D */   daddu    $a0, $s1, $zero
/* BBB570 802401F0 AE22007C */  sw        $v0, 0x7c($s1)
.L802401F4:
/* BBB574 802401F4 8E23007C */  lw        $v1, 0x7c($s1)
/* BBB578 802401F8 8E220074 */  lw        $v0, 0x74($s1)
/* BBB57C 802401FC 0060202D */  daddu     $a0, $v1, $zero
/* BBB580 80240200 00431021 */  addu      $v0, $v0, $v1
/* BBB584 80240204 04800004 */  bltz      $a0, .L80240218
/* BBB588 80240208 AE220074 */   sw       $v0, 0x74($s1)
/* BBB58C 8024020C 8E230078 */  lw        $v1, 0x78($s1)
/* BBB590 80240210 08090088 */  j         .L80240220
/* BBB594 80240214 0043102A */   slt      $v0, $v0, $v1
.L80240218:
/* BBB598 80240218 8E230078 */  lw        $v1, 0x78($s1)
/* BBB59C 8024021C 0062102A */  slt       $v0, $v1, $v0
.L80240220:
/* BBB5A0 80240220 14400003 */  bnez      $v0, .L80240230
/* BBB5A4 80240224 00000000 */   nop      
/* BBB5A8 80240228 AE230074 */  sw        $v1, 0x74($s1)
/* BBB5AC 8024022C 24120002 */  addiu     $s2, $zero, 2
.L80240230:
/* BBB5B0 80240230 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* BBB5B4 80240234 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* BBB5B8 80240238 96230076 */  lhu       $v1, 0x76($s1)
/* BBB5BC 8024023C 0240102D */  daddu     $v0, $s2, $zero
/* BBB5C0 80240240 A483015C */  sh        $v1, 0x15c($a0)
/* BBB5C4 80240244 8FBF001C */  lw        $ra, 0x1c($sp)
/* BBB5C8 80240248 8FB20018 */  lw        $s2, 0x18($sp)
/* BBB5CC 8024024C 8FB10014 */  lw        $s1, 0x14($sp)
/* BBB5D0 80240250 8FB00010 */  lw        $s0, 0x10($sp)
/* BBB5D4 80240254 03E00008 */  jr        $ra
/* BBB5D8 80240258 27BD0020 */   addiu    $sp, $sp, 0x20
