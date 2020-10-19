.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240460_A3FBA0
/* A3FBA0 80240460 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3FBA4 80240464 AFB00010 */  sw        $s0, 0x10($sp)
/* A3FBA8 80240468 0080802D */  daddu     $s0, $a0, $zero
/* A3FBAC 8024046C AFBF0014 */  sw        $ra, 0x14($sp)
/* A3FBB0 80240470 8E0300A8 */  lw        $v1, 0xa8($s0)
/* A3FBB4 80240474 8E020088 */  lw        $v0, 0x88($s0)
/* A3FBB8 80240478 00621821 */  addu      $v1, $v1, $v0
/* A3FBBC 8024047C 04610004 */  bgez      $v1, .L80240490
/* A3FBC0 80240480 AE0300A8 */   sw       $v1, 0xa8($s0)
/* A3FBC4 80240484 3C020002 */  lui       $v0, 2
/* A3FBC8 80240488 08090128 */  j         .L802404A0
/* A3FBCC 8024048C 00621021 */   addu     $v0, $v1, $v0
.L80240490:
/* A3FBD0 80240490 3C040002 */  lui       $a0, 2
/* A3FBD4 80240494 0083102A */  slt       $v0, $a0, $v1
/* A3FBD8 80240498 10400002 */  beqz      $v0, .L802404A4
/* A3FBDC 8024049C 00641023 */   subu     $v0, $v1, $a0
.L802404A0:
/* A3FBE0 802404A0 AE0200A8 */  sw        $v0, 0xa8($s0)
.L802404A4:
/* A3FBE4 802404A4 8E0300AC */  lw        $v1, 0xac($s0)
/* A3FBE8 802404A8 8E02008C */  lw        $v0, 0x8c($s0)
/* A3FBEC 802404AC 00621821 */  addu      $v1, $v1, $v0
/* A3FBF0 802404B0 04610004 */  bgez      $v1, .L802404C4
/* A3FBF4 802404B4 AE0300AC */   sw       $v1, 0xac($s0)
/* A3FBF8 802404B8 3C020002 */  lui       $v0, 2
/* A3FBFC 802404BC 08090135 */  j         .L802404D4
/* A3FC00 802404C0 00621021 */   addu     $v0, $v1, $v0
.L802404C4:
/* A3FC04 802404C4 3C040002 */  lui       $a0, 2
/* A3FC08 802404C8 0083102A */  slt       $v0, $a0, $v1
/* A3FC0C 802404CC 10400002 */  beqz      $v0, .L802404D8
/* A3FC10 802404D0 00641023 */   subu     $v0, $v1, $a0
.L802404D4:
/* A3FC14 802404D4 AE0200AC */  sw        $v0, 0xac($s0)
.L802404D8:
/* A3FC18 802404D8 8E0300B0 */  lw        $v1, 0xb0($s0)
/* A3FC1C 802404DC 8E020090 */  lw        $v0, 0x90($s0)
/* A3FC20 802404E0 00621821 */  addu      $v1, $v1, $v0
/* A3FC24 802404E4 04610004 */  bgez      $v1, .L802404F8
/* A3FC28 802404E8 AE0300B0 */   sw       $v1, 0xb0($s0)
/* A3FC2C 802404EC 3C020002 */  lui       $v0, 2
/* A3FC30 802404F0 08090142 */  j         .L80240508
/* A3FC34 802404F4 00621021 */   addu     $v0, $v1, $v0
.L802404F8:
/* A3FC38 802404F8 3C040002 */  lui       $a0, 2
/* A3FC3C 802404FC 0083102A */  slt       $v0, $a0, $v1
/* A3FC40 80240500 10400002 */  beqz      $v0, .L8024050C
/* A3FC44 80240504 00641023 */   subu     $v0, $v1, $a0
.L80240508:
/* A3FC48 80240508 AE0200B0 */  sw        $v0, 0xb0($s0)
.L8024050C:
/* A3FC4C 8024050C 8E0300B4 */  lw        $v1, 0xb4($s0)
/* A3FC50 80240510 8E020094 */  lw        $v0, 0x94($s0)
/* A3FC54 80240514 00621821 */  addu      $v1, $v1, $v0
/* A3FC58 80240518 04610004 */  bgez      $v1, .L8024052C
/* A3FC5C 8024051C AE0300B4 */   sw       $v1, 0xb4($s0)
/* A3FC60 80240520 3C020002 */  lui       $v0, 2
/* A3FC64 80240524 0809014F */  j         .L8024053C
/* A3FC68 80240528 00621021 */   addu     $v0, $v1, $v0
.L8024052C:
/* A3FC6C 8024052C 3C040002 */  lui       $a0, 2
/* A3FC70 80240530 0083102A */  slt       $v0, $a0, $v1
/* A3FC74 80240534 10400002 */  beqz      $v0, .L80240540
/* A3FC78 80240538 00641023 */   subu     $v0, $v1, $a0
.L8024053C:
/* A3FC7C 8024053C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240540:
/* A3FC80 80240540 8E040084 */  lw        $a0, 0x84($s0)
/* A3FC84 80240544 0C046F07 */  jal       set_main_pan_u
/* A3FC88 80240548 8E0500A8 */   lw       $a1, 0xa8($s0)
/* A3FC8C 8024054C 8E040084 */  lw        $a0, 0x84($s0)
/* A3FC90 80240550 0C046F0D */  jal       set_main_pan_v
/* A3FC94 80240554 8E0500AC */   lw       $a1, 0xac($s0)
/* A3FC98 80240558 8E040084 */  lw        $a0, 0x84($s0)
/* A3FC9C 8024055C 0C046F13 */  jal       set_aux_pan_u
/* A3FCA0 80240560 8E0500B0 */   lw       $a1, 0xb0($s0)
/* A3FCA4 80240564 8E040084 */  lw        $a0, 0x84($s0)
/* A3FCA8 80240568 0C046F19 */  jal       set_aux_pan_v
/* A3FCAC 8024056C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* A3FCB0 80240570 8FBF0014 */  lw        $ra, 0x14($sp)
/* A3FCB4 80240574 8FB00010 */  lw        $s0, 0x10($sp)
/* A3FCB8 80240578 0000102D */  daddu     $v0, $zero, $zero
/* A3FCBC 8024057C 03E00008 */  jr        $ra
/* A3FCC0 80240580 27BD0018 */   addiu    $sp, $sp, 0x18
