.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_ADAEF0
/* ADAEF0 80240050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ADAEF4 80240054 AFB00010 */  sw        $s0, 0x10($sp)
/* ADAEF8 80240058 0080802D */  daddu     $s0, $a0, $zero
/* ADAEFC 8024005C AFBF0014 */  sw        $ra, 0x14($sp)
/* ADAF00 80240060 8E0300A8 */  lw        $v1, 0xa8($s0)
/* ADAF04 80240064 8E020088 */  lw        $v0, 0x88($s0)
/* ADAF08 80240068 00621821 */  addu      $v1, $v1, $v0
/* ADAF0C 8024006C 04610004 */  bgez      $v1, .L80240080
/* ADAF10 80240070 AE0300A8 */   sw       $v1, 0xa8($s0)
/* ADAF14 80240074 3C020002 */  lui       $v0, 2
/* ADAF18 80240078 08090024 */  j         .L80240090
/* ADAF1C 8024007C 00621021 */   addu     $v0, $v1, $v0
.L80240080:
/* ADAF20 80240080 3C040002 */  lui       $a0, 2
/* ADAF24 80240084 0083102A */  slt       $v0, $a0, $v1
/* ADAF28 80240088 10400002 */  beqz      $v0, .L80240094
/* ADAF2C 8024008C 00641023 */   subu     $v0, $v1, $a0
.L80240090:
/* ADAF30 80240090 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240094:
/* ADAF34 80240094 8E0300AC */  lw        $v1, 0xac($s0)
/* ADAF38 80240098 8E02008C */  lw        $v0, 0x8c($s0)
/* ADAF3C 8024009C 00621821 */  addu      $v1, $v1, $v0
/* ADAF40 802400A0 04610004 */  bgez      $v1, .L802400B4
/* ADAF44 802400A4 AE0300AC */   sw       $v1, 0xac($s0)
/* ADAF48 802400A8 3C020002 */  lui       $v0, 2
/* ADAF4C 802400AC 08090031 */  j         .L802400C4
/* ADAF50 802400B0 00621021 */   addu     $v0, $v1, $v0
.L802400B4:
/* ADAF54 802400B4 3C040002 */  lui       $a0, 2
/* ADAF58 802400B8 0083102A */  slt       $v0, $a0, $v1
/* ADAF5C 802400BC 10400002 */  beqz      $v0, .L802400C8
/* ADAF60 802400C0 00641023 */   subu     $v0, $v1, $a0
.L802400C4:
/* ADAF64 802400C4 AE0200AC */  sw        $v0, 0xac($s0)
.L802400C8:
/* ADAF68 802400C8 8E0300B0 */  lw        $v1, 0xb0($s0)
/* ADAF6C 802400CC 8E020090 */  lw        $v0, 0x90($s0)
/* ADAF70 802400D0 00621821 */  addu      $v1, $v1, $v0
/* ADAF74 802400D4 04610004 */  bgez      $v1, .L802400E8
/* ADAF78 802400D8 AE0300B0 */   sw       $v1, 0xb0($s0)
/* ADAF7C 802400DC 3C020002 */  lui       $v0, 2
/* ADAF80 802400E0 0809003E */  j         .L802400F8
/* ADAF84 802400E4 00621021 */   addu     $v0, $v1, $v0
.L802400E8:
/* ADAF88 802400E8 3C040002 */  lui       $a0, 2
/* ADAF8C 802400EC 0083102A */  slt       $v0, $a0, $v1
/* ADAF90 802400F0 10400002 */  beqz      $v0, .L802400FC
/* ADAF94 802400F4 00641023 */   subu     $v0, $v1, $a0
.L802400F8:
/* ADAF98 802400F8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400FC:
/* ADAF9C 802400FC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* ADAFA0 80240100 8E020094 */  lw        $v0, 0x94($s0)
/* ADAFA4 80240104 00621821 */  addu      $v1, $v1, $v0
/* ADAFA8 80240108 04610004 */  bgez      $v1, .L8024011C
/* ADAFAC 8024010C AE0300B4 */   sw       $v1, 0xb4($s0)
/* ADAFB0 80240110 3C020002 */  lui       $v0, 2
/* ADAFB4 80240114 0809004B */  j         .L8024012C
/* ADAFB8 80240118 00621021 */   addu     $v0, $v1, $v0
.L8024011C:
/* ADAFBC 8024011C 3C040002 */  lui       $a0, 2
/* ADAFC0 80240120 0083102A */  slt       $v0, $a0, $v1
/* ADAFC4 80240124 10400002 */  beqz      $v0, .L80240130
/* ADAFC8 80240128 00641023 */   subu     $v0, $v1, $a0
.L8024012C:
/* ADAFCC 8024012C AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240130:
/* ADAFD0 80240130 8E040084 */  lw        $a0, 0x84($s0)
/* ADAFD4 80240134 0C046F07 */  jal       set_main_pan_u
/* ADAFD8 80240138 8E0500A8 */   lw       $a1, 0xa8($s0)
/* ADAFDC 8024013C 8E040084 */  lw        $a0, 0x84($s0)
/* ADAFE0 80240140 0C046F0D */  jal       set_main_pan_v
/* ADAFE4 80240144 8E0500AC */   lw       $a1, 0xac($s0)
/* ADAFE8 80240148 8E040084 */  lw        $a0, 0x84($s0)
/* ADAFEC 8024014C 0C046F13 */  jal       set_aux_pan_u
/* ADAFF0 80240150 8E0500B0 */   lw       $a1, 0xb0($s0)
/* ADAFF4 80240154 8E040084 */  lw        $a0, 0x84($s0)
/* ADAFF8 80240158 0C046F19 */  jal       set_aux_pan_v
/* ADAFFC 8024015C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* ADB000 80240160 8FBF0014 */  lw        $ra, 0x14($sp)
/* ADB004 80240164 8FB00010 */  lw        $s0, 0x10($sp)
/* ADB008 80240168 0000102D */  daddu     $v0, $zero, $zero
/* ADB00C 8024016C 03E00008 */  jr        $ra
/* ADB010 80240170 27BD0018 */   addiu    $sp, $sp, 0x18
