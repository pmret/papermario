.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243230_C42FE0
/* C42FE0 80243230 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C42FE4 80243234 AFB20028 */  sw        $s2, 0x28($sp)
/* C42FE8 80243238 0080902D */  daddu     $s2, $a0, $zero
/* C42FEC 8024323C AFBF002C */  sw        $ra, 0x2c($sp)
/* C42FF0 80243240 AFB10024 */  sw        $s1, 0x24($sp)
/* C42FF4 80243244 AFB00020 */  sw        $s0, 0x20($sp)
/* C42FF8 80243248 8E500148 */  lw        $s0, 0x148($s2)
/* C42FFC 8024324C 0C00EABB */  jal       get_npc_unsafe
/* C43000 80243250 86040008 */   lh       $a0, 8($s0)
/* C43004 80243254 2404FEFF */  addiu     $a0, $zero, -0x101
/* C43008 80243258 0040882D */  daddu     $s1, $v0, $zero
/* C4300C 8024325C 0000282D */  daddu     $a1, $zero, $zero
/* C43010 80243260 8E03006C */  lw        $v1, 0x6c($s0)
/* C43014 80243264 00A0302D */  daddu     $a2, $a1, $zero
/* C43018 80243268 00641824 */  and       $v1, $v1, $a0
/* C4301C 8024326C AE03006C */  sw        $v1, 0x6c($s0)
/* C43020 80243270 AFA00010 */  sw        $zero, 0x10($sp)
/* C43024 80243274 AFA00014 */  sw        $zero, 0x14($sp)
/* C43028 80243278 AFA00018 */  sw        $zero, 0x18($sp)
/* C4302C 8024327C 8E240024 */  lw        $a0, 0x24($s1)
/* C43030 80243280 0C0B7A25 */  jal       func_802DE894
/* C43034 80243284 00A0382D */   daddu    $a3, $a1, $zero
/* C43038 80243288 8E02006C */  lw        $v0, 0x6c($s0)
/* C4303C 8024328C 30421000 */  andi      $v0, $v0, 0x1000
/* C43040 80243290 10400008 */  beqz      $v0, .L802432B4
/* C43044 80243294 00000000 */   nop
/* C43048 80243298 3C048000 */  lui       $a0, 0x8000
/* C4304C 8024329C 0C05271B */  jal       sfx_stop_sound
/* C43050 802432A0 34840011 */   ori      $a0, $a0, 0x11
/* C43054 802432A4 8E02006C */  lw        $v0, 0x6c($s0)
/* C43058 802432A8 2403EFFF */  addiu     $v1, $zero, -0x1001
/* C4305C 802432AC 00431024 */  and       $v0, $v0, $v1
/* C43060 802432B0 AE02006C */  sw        $v0, 0x6c($s0)
.L802432B4:
/* C43064 802432B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* C43068 802432B8 8C430024 */  lw        $v1, 0x24($v0)
/* C4306C 802432BC 24020014 */  addiu     $v0, $zero, 0x14
/* C43070 802432C0 A622008E */  sh        $v0, 0x8e($s1)
/* C43074 802432C4 24020011 */  addiu     $v0, $zero, 0x11
/* C43078 802432C8 AE230028 */  sw        $v1, 0x28($s1)
/* C4307C 802432CC AE420070 */  sw        $v0, 0x70($s2)
/* C43080 802432D0 8FBF002C */  lw        $ra, 0x2c($sp)
/* C43084 802432D4 8FB20028 */  lw        $s2, 0x28($sp)
/* C43088 802432D8 8FB10024 */  lw        $s1, 0x24($sp)
/* C4308C 802432DC 8FB00020 */  lw        $s0, 0x20($sp)
/* C43090 802432E0 03E00008 */  jr        $ra
/* C43094 802432E4 27BD0030 */   addiu    $sp, $sp, 0x30
