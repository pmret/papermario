.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802194B8_66B238
/* 66B238 802194B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66B23C 802194BC AFB20018 */  sw        $s2, 0x18($sp)
/* 66B240 802194C0 0080902D */  daddu     $s2, $a0, $zero
/* 66B244 802194C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B248 802194C8 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 66B24C 802194CC 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 66B250 802194D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 66B254 802194D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B258 802194D8 8E50000C */  lw        $s0, 0xc($s2)
/* 66B25C 802194DC 82260012 */  lb        $a2, 0x12($s1)
/* 66B260 802194E0 8E050000 */  lw        $a1, ($s0)
/* 66B264 802194E4 0C0B2026 */  jal       evt_set_variable
/* 66B268 802194E8 26100004 */   addiu    $s0, $s0, 4
/* 66B26C 802194EC 82220012 */  lb        $v0, 0x12($s1)
/* 66B270 802194F0 8E050000 */  lw        $a1, ($s0)
/* 66B274 802194F4 000210C0 */  sll       $v0, $v0, 3
/* 66B278 802194F8 00511021 */  addu      $v0, $v0, $s1
/* 66B27C 802194FC 80460015 */  lb        $a2, 0x15($v0)
/* 66B280 80219500 0C0B2026 */  jal       evt_set_variable
/* 66B284 80219504 0240202D */   daddu    $a0, $s2, $zero
/* 66B288 80219508 8FBF001C */  lw        $ra, 0x1c($sp)
/* 66B28C 8021950C 8FB20018 */  lw        $s2, 0x18($sp)
/* 66B290 80219510 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B294 80219514 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B298 80219518 24020002 */  addiu     $v0, $zero, 2
/* 66B29C 8021951C 03E00008 */  jr        $ra
/* 66B2A0 80219520 27BD0020 */   addiu    $sp, $sp, 0x20
