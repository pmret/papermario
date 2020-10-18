.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD148_325070
/* 3250B8 802BD148 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3250BC 802BD14C AFB10014 */  sw        $s1, 0x14($sp)
/* 3250C0 802BD150 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 3250C4 802BD154 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 3250C8 802BD158 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3250CC 802BD15C AFB00010 */  sw        $s0, 0x10($sp)
/* 3250D0 802BD160 8C90014C */  lw        $s0, 0x14c($a0)
/* 3250D4 802BD164 10A00003 */  beqz      $a1, .L802BD174
/* 3250D8 802BD168 0200202D */   daddu    $a0, $s0, $zero
/* 3250DC 802BD16C 0C03B4C4 */  jal       enable_partner_flying
/* 3250E0 802BD170 24050001 */   addiu    $a1, $zero, 1
.L802BD174:
/* 3250E4 802BD174 0C03B52E */  jal       update_player_move_history
/* 3250E8 802BD178 0200202D */   daddu    $a0, $s0, $zero
/* 3250EC 802BD17C 0C03B574 */  jal       func_800ED5D0
/* 3250F0 802BD180 0200202D */   daddu    $a0, $s0, $zero
/* 3250F4 802BD184 8E220320 */  lw        $v0, 0x320($s1)
/* 3250F8 802BD188 24420001 */  addiu     $v0, $v0, 1
/* 3250FC 802BD18C AE220320 */  sw        $v0, 0x320($s1)
/* 325100 802BD190 8FBF0018 */  lw        $ra, 0x18($sp)
/* 325104 802BD194 8FB10014 */  lw        $s1, 0x14($sp)
/* 325108 802BD198 8FB00010 */  lw        $s0, 0x10($sp)
/* 32510C 802BD19C 0000102D */  daddu     $v0, $zero, $zero
/* 325110 802BD1A0 03E00008 */  jr        $ra
/* 325114 802BD1A4 27BD0020 */   addiu    $sp, $sp, 0x20
