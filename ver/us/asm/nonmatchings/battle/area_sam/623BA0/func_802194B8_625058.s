.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802194B8_625058
/* 625058 802194B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 62505C 802194BC AFB20018 */  sw        $s2, 0x18($sp)
/* 625060 802194C0 0080902D */  daddu     $s2, $a0, $zero
/* 625064 802194C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 625068 802194C8 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 62506C 802194CC 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 625070 802194D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 625074 802194D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 625078 802194D8 8E50000C */  lw        $s0, 0xc($s2)
/* 62507C 802194DC 82260012 */  lb        $a2, 0x12($s1)
/* 625080 802194E0 8E050000 */  lw        $a1, ($s0)
/* 625084 802194E4 0C0B2026 */  jal       evt_set_variable
/* 625088 802194E8 26100004 */   addiu    $s0, $s0, 4
/* 62508C 802194EC 82220012 */  lb        $v0, 0x12($s1)
/* 625090 802194F0 8E050000 */  lw        $a1, ($s0)
/* 625094 802194F4 000210C0 */  sll       $v0, $v0, 3
/* 625098 802194F8 00511021 */  addu      $v0, $v0, $s1
/* 62509C 802194FC 80460015 */  lb        $a2, 0x15($v0)
/* 6250A0 80219500 0C0B2026 */  jal       evt_set_variable
/* 6250A4 80219504 0240202D */   daddu    $a0, $s2, $zero
/* 6250A8 80219508 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6250AC 8021950C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6250B0 80219510 8FB10014 */  lw        $s1, 0x14($sp)
/* 6250B4 80219514 8FB00010 */  lw        $s0, 0x10($sp)
/* 6250B8 80219518 24020002 */  addiu     $v0, $zero, 2
/* 6250BC 8021951C 03E00008 */  jr        $ra
/* 6250C0 80219520 27BD0020 */   addiu    $sp, $sp, 0x20
