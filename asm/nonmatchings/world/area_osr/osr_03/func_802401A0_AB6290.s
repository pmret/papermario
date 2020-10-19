.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401A0_AB6430
/* AB6430 802401A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB6434 802401A4 AFB00010 */  sw        $s0, 0x10($sp)
/* AB6438 802401A8 0080802D */  daddu     $s0, $a0, $zero
/* AB643C 802401AC 10A00003 */  beqz      $a1, .L802401BC
/* AB6440 802401B0 AFBF0014 */   sw       $ra, 0x14($sp)
/* AB6444 802401B4 AE000074 */  sw        $zero, 0x74($s0)
/* AB6448 802401B8 AE000078 */  sw        $zero, 0x78($s0)
.L802401BC:
/* AB644C 802401BC 8E030078 */  lw        $v1, 0x78($s0)
/* AB6450 802401C0 10600005 */  beqz      $v1, .L802401D8
/* AB6454 802401C4 24020001 */   addiu    $v0, $zero, 1
/* AB6458 802401C8 1062001A */  beq       $v1, $v0, .L80240234
/* AB645C 802401CC 0000102D */   daddu    $v0, $zero, $zero
/* AB6460 802401D0 080900A0 */  j         .L80240280
/* AB6464 802401D4 00000000 */   nop      
.L802401D8:
/* AB6468 802401D8 0000202D */  daddu     $a0, $zero, $zero
/* AB646C 802401DC 240500D0 */  addiu     $a1, $zero, 0xd0
/* AB6470 802401E0 00A0302D */  daddu     $a2, $a1, $zero
/* AB6474 802401E4 0C04DF84 */  jal       func_80137E10
/* AB6478 802401E8 00A0382D */   daddu    $a3, $a1, $zero
/* AB647C 802401EC C6000074 */  lwc1      $f0, 0x74($s0)
/* AB6480 802401F0 46800020 */  cvt.s.w   $f0, $f0
/* AB6484 802401F4 44050000 */  mfc1      $a1, $f0
/* AB6488 802401F8 0C04DF62 */  jal       func_80137D88
/* AB648C 802401FC 24040001 */   addiu    $a0, $zero, 1
/* AB6490 80240200 8E020074 */  lw        $v0, 0x74($s0)
/* AB6494 80240204 240300FF */  addiu     $v1, $zero, 0xff
/* AB6498 80240208 14430004 */  bne       $v0, $v1, .L8024021C
/* AB649C 8024020C 24420040 */   addiu    $v0, $v0, 0x40
/* AB64A0 80240210 24020001 */  addiu     $v0, $zero, 1
/* AB64A4 80240214 0809009F */  j         .L8024027C
/* AB64A8 80240218 AE020078 */   sw       $v0, 0x78($s0)
.L8024021C:
/* AB64AC 8024021C AE020074 */  sw        $v0, 0x74($s0)
/* AB64B0 80240220 28420100 */  slti      $v0, $v0, 0x100
/* AB64B4 80240224 50400015 */  beql      $v0, $zero, .L8024027C
/* AB64B8 80240228 AE030074 */   sw       $v1, 0x74($s0)
/* AB64BC 8024022C 080900A0 */  j         .L80240280
/* AB64C0 80240230 0000102D */   daddu    $v0, $zero, $zero
.L80240234:
/* AB64C4 80240234 0000202D */  daddu     $a0, $zero, $zero
/* AB64C8 80240238 240500D0 */  addiu     $a1, $zero, 0xd0
/* AB64CC 8024023C 00A0302D */  daddu     $a2, $a1, $zero
/* AB64D0 80240240 0C04DF84 */  jal       func_80137E10
/* AB64D4 80240244 00A0382D */   daddu    $a3, $a1, $zero
/* AB64D8 80240248 C6000074 */  lwc1      $f0, 0x74($s0)
/* AB64DC 8024024C 46800020 */  cvt.s.w   $f0, $f0
/* AB64E0 80240250 44050000 */  mfc1      $a1, $f0
/* AB64E4 80240254 0C04DF62 */  jal       func_80137D88
/* AB64E8 80240258 24040001 */   addiu    $a0, $zero, 1
/* AB64EC 8024025C 8E020074 */  lw        $v0, 0x74($s0)
/* AB64F0 80240260 14400003 */  bnez      $v0, .L80240270
/* AB64F4 80240264 2442FFC0 */   addiu    $v0, $v0, -0x40
/* AB64F8 80240268 080900A0 */  j         .L80240280
/* AB64FC 8024026C 24020002 */   addiu    $v0, $zero, 2
.L80240270:
/* AB6500 80240270 1C400002 */  bgtz      $v0, .L8024027C
/* AB6504 80240274 AE020074 */   sw       $v0, 0x74($s0)
/* AB6508 80240278 AE000074 */  sw        $zero, 0x74($s0)
.L8024027C:
/* AB650C 8024027C 0000102D */  daddu     $v0, $zero, $zero
.L80240280:
/* AB6510 80240280 8FBF0014 */  lw        $ra, 0x14($sp)
/* AB6514 80240284 8FB00010 */  lw        $s0, 0x10($sp)
/* AB6518 80240288 03E00008 */  jr        $ra
/* AB651C 8024028C 27BD0018 */   addiu    $sp, $sp, 0x18
