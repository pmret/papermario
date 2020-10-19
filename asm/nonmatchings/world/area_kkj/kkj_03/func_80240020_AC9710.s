.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_AC9730
/* AC9730 80240020 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AC9734 80240024 AFB00010 */  sw        $s0, 0x10($sp)
/* AC9738 80240028 0080802D */  daddu     $s0, $a0, $zero
/* AC973C 8024002C AFBF0014 */  sw        $ra, 0x14($sp)
/* AC9740 80240030 8E0300A8 */  lw        $v1, 0xa8($s0)
/* AC9744 80240034 8E020088 */  lw        $v0, 0x88($s0)
/* AC9748 80240038 00621821 */  addu      $v1, $v1, $v0
/* AC974C 8024003C 04610004 */  bgez      $v1, .L80240050
/* AC9750 80240040 AE0300A8 */   sw       $v1, 0xa8($s0)
/* AC9754 80240044 3C020002 */  lui       $v0, 2
/* AC9758 80240048 08090018 */  j         .L80240060
/* AC975C 8024004C 00621021 */   addu     $v0, $v1, $v0
.L80240050:
/* AC9760 80240050 3C040002 */  lui       $a0, 2
/* AC9764 80240054 0083102A */  slt       $v0, $a0, $v1
/* AC9768 80240058 10400002 */  beqz      $v0, .L80240064
/* AC976C 8024005C 00641023 */   subu     $v0, $v1, $a0
.L80240060:
/* AC9770 80240060 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80240064:
/* AC9774 80240064 8E0300AC */  lw        $v1, 0xac($s0)
/* AC9778 80240068 8E02008C */  lw        $v0, 0x8c($s0)
/* AC977C 8024006C 00621821 */  addu      $v1, $v1, $v0
/* AC9780 80240070 04610004 */  bgez      $v1, .L80240084
/* AC9784 80240074 AE0300AC */   sw       $v1, 0xac($s0)
/* AC9788 80240078 3C020002 */  lui       $v0, 2
/* AC978C 8024007C 08090025 */  j         .L80240094
/* AC9790 80240080 00621021 */   addu     $v0, $v1, $v0
.L80240084:
/* AC9794 80240084 3C040002 */  lui       $a0, 2
/* AC9798 80240088 0083102A */  slt       $v0, $a0, $v1
/* AC979C 8024008C 10400002 */  beqz      $v0, .L80240098
/* AC97A0 80240090 00641023 */   subu     $v0, $v1, $a0
.L80240094:
/* AC97A4 80240094 AE0200AC */  sw        $v0, 0xac($s0)
.L80240098:
/* AC97A8 80240098 8E0300B0 */  lw        $v1, 0xb0($s0)
/* AC97AC 8024009C 8E020090 */  lw        $v0, 0x90($s0)
/* AC97B0 802400A0 00621821 */  addu      $v1, $v1, $v0
/* AC97B4 802400A4 04610004 */  bgez      $v1, .L802400B8
/* AC97B8 802400A8 AE0300B0 */   sw       $v1, 0xb0($s0)
/* AC97BC 802400AC 3C020002 */  lui       $v0, 2
/* AC97C0 802400B0 08090032 */  j         .L802400C8
/* AC97C4 802400B4 00621021 */   addu     $v0, $v1, $v0
.L802400B8:
/* AC97C8 802400B8 3C040002 */  lui       $a0, 2
/* AC97CC 802400BC 0083102A */  slt       $v0, $a0, $v1
/* AC97D0 802400C0 10400002 */  beqz      $v0, .L802400CC
/* AC97D4 802400C4 00641023 */   subu     $v0, $v1, $a0
.L802400C8:
/* AC97D8 802400C8 AE0200B0 */  sw        $v0, 0xb0($s0)
.L802400CC:
/* AC97DC 802400CC 8E0300B4 */  lw        $v1, 0xb4($s0)
/* AC97E0 802400D0 8E020094 */  lw        $v0, 0x94($s0)
/* AC97E4 802400D4 00621821 */  addu      $v1, $v1, $v0
/* AC97E8 802400D8 04610004 */  bgez      $v1, .L802400EC
/* AC97EC 802400DC AE0300B4 */   sw       $v1, 0xb4($s0)
/* AC97F0 802400E0 3C020002 */  lui       $v0, 2
/* AC97F4 802400E4 0809003F */  j         .L802400FC
/* AC97F8 802400E8 00621021 */   addu     $v0, $v1, $v0
.L802400EC:
/* AC97FC 802400EC 3C040002 */  lui       $a0, 2
/* AC9800 802400F0 0083102A */  slt       $v0, $a0, $v1
/* AC9804 802400F4 10400002 */  beqz      $v0, .L80240100
/* AC9808 802400F8 00641023 */   subu     $v0, $v1, $a0
.L802400FC:
/* AC980C 802400FC AE0200B4 */  sw        $v0, 0xb4($s0)
.L80240100:
/* AC9810 80240100 8E040084 */  lw        $a0, 0x84($s0)
/* AC9814 80240104 0C046F07 */  jal       set_main_pan_u
/* AC9818 80240108 8E0500A8 */   lw       $a1, 0xa8($s0)
/* AC981C 8024010C 8E040084 */  lw        $a0, 0x84($s0)
/* AC9820 80240110 0C046F0D */  jal       set_main_pan_v
/* AC9824 80240114 8E0500AC */   lw       $a1, 0xac($s0)
/* AC9828 80240118 8E040084 */  lw        $a0, 0x84($s0)
/* AC982C 8024011C 0C046F13 */  jal       set_aux_pan_u
/* AC9830 80240120 8E0500B0 */   lw       $a1, 0xb0($s0)
/* AC9834 80240124 8E040084 */  lw        $a0, 0x84($s0)
/* AC9838 80240128 0C046F19 */  jal       set_aux_pan_v
/* AC983C 8024012C 8E0500B4 */   lw       $a1, 0xb4($s0)
/* AC9840 80240130 8FBF0014 */  lw        $ra, 0x14($sp)
/* AC9844 80240134 8FB00010 */  lw        $s0, 0x10($sp)
/* AC9848 80240138 0000102D */  daddu     $v0, $zero, $zero
/* AC984C 8024013C 03E00008 */  jr        $ra
/* AC9850 80240140 27BD0018 */   addiu    $sp, $sp, 0x18
