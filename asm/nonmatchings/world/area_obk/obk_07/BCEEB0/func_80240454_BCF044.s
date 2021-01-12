.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240454_BCF044
/* BCF044 80240454 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCF048 80240458 AFB10014 */  sw        $s1, 0x14($sp)
/* BCF04C 8024045C 0080882D */  daddu     $s1, $a0, $zero
/* BCF050 80240460 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCF054 80240464 AFB00010 */  sw        $s0, 0x10($sp)
/* BCF058 80240468 8E240088 */  lw        $a0, 0x88($s1)
/* BCF05C 8024046C 1480000B */  bnez      $a0, .L8024049C
/* BCF060 80240470 8E300084 */   lw       $s0, 0x84($s1)
/* BCF064 80240474 0C00A67F */  jal       rand_int
/* BCF068 80240478 24040003 */   addiu    $a0, $zero, 3
/* BCF06C 8024047C 00021040 */  sll       $v0, $v0, 1
/* BCF070 80240480 3C018024 */  lui       $at, %hi(D_8024292C)
/* BCF074 80240484 00220821 */  addu      $at, $at, $v0
/* BCF078 80240488 8422292C */  lh        $v0, %lo(D_8024292C)($at)
/* BCF07C 8024048C 24040032 */  addiu     $a0, $zero, 0x32
/* BCF080 80240490 0C00A67F */  jal       rand_int
/* BCF084 80240494 AE220078 */   sw       $v0, 0x78($s1)
/* BCF088 80240498 2444001E */  addiu     $a0, $v0, 0x1e
.L8024049C:
/* BCF08C 8024049C 8E230078 */  lw        $v1, 0x78($s1)
/* BCF090 802404A0 0203102A */  slt       $v0, $s0, $v1
/* BCF094 802404A4 10400006 */  beqz      $v0, .L802404C0
/* BCF098 802404A8 2484FFFF */   addiu    $a0, $a0, -1
/* BCF09C 802404AC 2610000A */  addiu     $s0, $s0, 0xa
/* BCF0A0 802404B0 0070102A */  slt       $v0, $v1, $s0
/* BCF0A4 802404B4 5040000A */  beql      $v0, $zero, .L802404E0
/* BCF0A8 802404B8 AE300084 */   sw       $s0, 0x84($s1)
/* BCF0AC 802404BC 0060802D */  daddu     $s0, $v1, $zero
.L802404C0:
/* BCF0B0 802404C0 0070102A */  slt       $v0, $v1, $s0
/* BCF0B4 802404C4 50400006 */  beql      $v0, $zero, .L802404E0
/* BCF0B8 802404C8 AE300084 */   sw       $s0, 0x84($s1)
/* BCF0BC 802404CC 2610FFF6 */  addiu     $s0, $s0, -0xa
/* BCF0C0 802404D0 0203102A */  slt       $v0, $s0, $v1
/* BCF0C4 802404D4 54400001 */  bnel      $v0, $zero, .L802404DC
/* BCF0C8 802404D8 0060802D */   daddu    $s0, $v1, $zero
.L802404DC:
/* BCF0CC 802404DC AE300084 */  sw        $s0, 0x84($s1)
.L802404E0:
/* BCF0D0 802404E0 AE240088 */  sw        $a0, 0x88($s1)
/* BCF0D4 802404E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCF0D8 802404E8 8FB10014 */  lw        $s1, 0x14($sp)
/* BCF0DC 802404EC 8FB00010 */  lw        $s0, 0x10($sp)
/* BCF0E0 802404F0 24020002 */  addiu     $v0, $zero, 2
/* BCF0E4 802404F4 03E00008 */  jr        $ra
/* BCF0E8 802404F8 27BD0020 */   addiu    $sp, $sp, 0x20
/* BCF0EC 802404FC 00000000 */  nop
