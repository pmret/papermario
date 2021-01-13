.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B61C0_E24AE0
/* E24AE0 802B61C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E24AE4 802B61C4 3C038016 */  lui       $v1, %hi(gCollisionStatus)
/* E24AE8 802B61C8 2463A550 */  addiu     $v1, $v1, %lo(gCollisionStatus)
/* E24AEC 802B61CC AFB00018 */  sw        $s0, 0x18($sp)
/* E24AF0 802B61D0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24AF4 802B61D4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24AF8 802B61D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* E24AFC 802B61DC AFB1001C */  sw        $s1, 0x1c($sp)
/* E24B00 802B61E0 8E020004 */  lw        $v0, 4($s0)
/* E24B04 802B61E4 30421000 */  andi      $v0, $v0, 0x1000
/* E24B08 802B61E8 10400005 */  beqz      $v0, .L802B6200
/* E24B0C 802B61EC 0060882D */   daddu    $s1, $v1, $zero
/* E24B10 802B61F0 0C0AD913 */  jal       func_802B644C_E24D6C
/* E24B14 802B61F4 00000000 */   nop
/* E24B18 802B61F8 080AD8AE */  j         .L802B62B8
/* E24B1C 802B61FC 00000000 */   nop
.L802B6200:
/* E24B20 802B6200 8E040000 */  lw        $a0, ($s0)
/* E24B24 802B6204 04810012 */  bgez      $a0, .L802B6250
/* E24B28 802B6208 3C027F77 */   lui      $v0, 0x7f77
/* E24B2C 802B620C 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E24B30 802B6210 C6000028 */  lwc1      $f0, 0x28($s0)
/* E24B34 802B6214 C6020030 */  lwc1      $f2, 0x30($s0)
/* E24B38 802B6218 94630002 */  lhu       $v1, 2($v1)
/* E24B3C 802B621C 00821024 */  and       $v0, $a0, $v0
/* E24B40 802B6220 AE020000 */  sw        $v0, ($s0)
/* E24B44 802B6224 A20000B6 */  sb        $zero, 0xb6($s0)
/* E24B48 802B6228 A60000C0 */  sh        $zero, 0xc0($s0)
/* E24B4C 802B622C A60000C2 */  sh        $zero, 0xc2($s0)
/* E24B50 802B6230 30634000 */  andi      $v1, $v1, 0x4000
/* E24B54 802B6234 E6000044 */  swc1      $f0, 0x44($s0)
/* E24B58 802B6238 14600003 */  bnez      $v1, .L802B6248
/* E24B5C 802B623C E6020048 */   swc1     $f2, 0x48($s0)
/* E24B60 802B6240 0C03954C */  jal       func_800E5530
/* E24B64 802B6244 00000000 */   nop
.L802B6248:
/* E24B68 802B6248 2402FFFF */  addiu     $v0, $zero, -1
/* E24B6C 802B624C A6220004 */  sh        $v0, 4($s1)
.L802B6250:
/* E24B70 802B6250 C6020054 */  lwc1      $f2, 0x54($s0)
/* E24B74 802B6254 3C013F19 */  lui       $at, 0x3f19
/* E24B78 802B6258 3421999A */  ori       $at, $at, 0x999a
/* E24B7C 802B625C 44810000 */  mtc1      $at, $f0
/* E24B80 802B6260 27A40010 */  addiu     $a0, $sp, 0x10
/* E24B84 802B6264 46001082 */  mul.s     $f2, $f2, $f0
/* E24B88 802B6268 00000000 */  nop
/* E24B8C 802B626C 920200B6 */  lbu       $v0, 0xb6($s0)
/* E24B90 802B6270 27A50014 */  addiu     $a1, $sp, 0x14
/* E24B94 802B6274 24420001 */  addiu     $v0, $v0, 1
/* E24B98 802B6278 A20200B6 */  sb        $v0, 0xb6($s0)
/* E24B9C 802B627C 0C0388C1 */  jal       input_to_move_vector
/* E24BA0 802B6280 E6020054 */   swc1     $f2, 0x54($s0)
/* E24BA4 802B6284 0C039858 */  jal       check_input_jump
/* E24BA8 802B6288 00000000 */   nop
/* E24BAC 802B628C C7A20014 */  lwc1      $f2, 0x14($sp)
/* E24BB0 802B6290 44800000 */  mtc1      $zero, $f0
/* E24BB4 802B6294 00000000 */  nop
/* E24BB8 802B6298 46001032 */  c.eq.s    $f2, $f0
/* E24BBC 802B629C 00000000 */  nop
/* E24BC0 802B62A0 45010003 */  bc1t      .L802B62B0
/* E24BC4 802B62A4 00000000 */   nop
/* E24BC8 802B62A8 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E24BCC 802B62AC E6000080 */  swc1      $f0, 0x80($s0)
.L802B62B0:
/* E24BD0 802B62B0 0C0397DA */  jal       update_locomotion_state
/* E24BD4 802B62B4 00000000 */   nop
.L802B62B8:
/* E24BD8 802B62B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* E24BDC 802B62BC 8FB1001C */  lw        $s1, 0x1c($sp)
/* E24BE0 802B62C0 8FB00018 */  lw        $s0, 0x18($sp)
/* E24BE4 802B62C4 03E00008 */  jr        $ra
/* E24BE8 802B62C8 27BD0028 */   addiu    $sp, $sp, 0x28
