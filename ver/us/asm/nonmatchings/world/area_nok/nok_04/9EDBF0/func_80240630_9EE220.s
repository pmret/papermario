.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240630_9EE220
/* 9EE220 80240630 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9EE224 80240634 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EE228 80240638 0080882D */  daddu     $s1, $a0, $zero
/* 9EE22C 8024063C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9EE230 80240640 AFB00010 */  sw        $s0, 0x10($sp)
/* 9EE234 80240644 8E30000C */  lw        $s0, 0xc($s1)
/* 9EE238 80240648 8E050000 */  lw        $a1, ($s0)
/* 9EE23C 8024064C 0C0B1EAF */  jal       evt_get_variable
/* 9EE240 80240650 26100004 */   addiu    $s0, $s0, 4
/* 9EE244 80240654 0040382D */  daddu     $a3, $v0, $zero
/* 9EE248 80240658 3C022AAA */  lui       $v0, 0x2aaa
/* 9EE24C 8024065C 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 9EE250 80240660 00E20018 */  mult      $a3, $v0
/* 9EE254 80240664 00071FC3 */  sra       $v1, $a3, 0x1f
/* 9EE258 80240668 8E050000 */  lw        $a1, ($s0)
/* 9EE25C 8024066C 00004010 */  mfhi      $t0
/* 9EE260 80240670 01031823 */  subu      $v1, $t0, $v1
/* 9EE264 80240674 00031040 */  sll       $v0, $v1, 1
/* 9EE268 80240678 00431021 */  addu      $v0, $v0, $v1
/* 9EE26C 8024067C 00021040 */  sll       $v0, $v0, 1
/* 9EE270 80240680 00E23023 */  subu      $a2, $a3, $v0
/* 9EE274 80240684 28C20004 */  slti      $v0, $a2, 4
/* 9EE278 80240688 10400003 */  beqz      $v0, .L80240698
/* 9EE27C 8024068C 00C0382D */   daddu    $a3, $a2, $zero
/* 9EE280 80240690 080901A9 */  j         .L802406A4
/* 9EE284 80240694 0220202D */   daddu    $a0, $s1, $zero
.L80240698:
/* 9EE288 80240698 0220202D */  daddu     $a0, $s1, $zero
/* 9EE28C 8024069C 24060006 */  addiu     $a2, $zero, 6
/* 9EE290 802406A0 00C73023 */  subu      $a2, $a2, $a3
.L802406A4:
/* 9EE294 802406A4 0C0B2026 */  jal       evt_set_variable
/* 9EE298 802406A8 00000000 */   nop
/* 9EE29C 802406AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9EE2A0 802406B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EE2A4 802406B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EE2A8 802406B8 24020002 */  addiu     $v0, $zero, 2
/* 9EE2AC 802406BC 03E00008 */  jr        $ra
/* 9EE2B0 802406C0 27BD0020 */   addiu    $sp, $sp, 0x20
