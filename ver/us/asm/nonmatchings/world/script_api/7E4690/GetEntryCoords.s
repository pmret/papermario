.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetEntryCoords
/* 7E4AB4 80283C34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7E4AB8 80283C38 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E4ABC 80283C3C 0080902D */  daddu     $s2, $a0, $zero
/* 7E4AC0 80283C40 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7E4AC4 80283C44 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7E4AC8 80283C48 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E4ACC 80283C4C AFB00010 */  sw        $s0, 0x10($sp)
/* 7E4AD0 80283C50 0C016AFA */  jal       get_current_map_header
/* 7E4AD4 80283C54 8E50000C */   lw       $s0, 0xc($s2)
/* 7E4AD8 80283C58 0240202D */  daddu     $a0, $s2, $zero
/* 7E4ADC 80283C5C 8C530014 */  lw        $s3, 0x14($v0)
/* 7E4AE0 80283C60 8E050000 */  lw        $a1, ($s0)
/* 7E4AE4 80283C64 0C0B1EAF */  jal       get_variable
/* 7E4AE8 80283C68 26100004 */   addiu    $s0, $s0, 4
/* 7E4AEC 80283C6C 8E050000 */  lw        $a1, ($s0)
/* 7E4AF0 80283C70 26100004 */  addiu     $s0, $s0, 4
/* 7E4AF4 80283C74 00028900 */  sll       $s1, $v0, 4
/* 7E4AF8 80283C78 02338821 */  addu      $s1, $s1, $s3
/* 7E4AFC 80283C7C C6200000 */  lwc1      $f0, ($s1)
/* 7E4B00 80283C80 4600008D */  trunc.w.s $f2, $f0
/* 7E4B04 80283C84 44061000 */  mfc1      $a2, $f2
/* 7E4B08 80283C88 0C0B2026 */  jal       evt_set_variable
/* 7E4B0C 80283C8C 0240202D */   daddu    $a0, $s2, $zero
/* 7E4B10 80283C90 8E050000 */  lw        $a1, ($s0)
/* 7E4B14 80283C94 26100004 */  addiu     $s0, $s0, 4
/* 7E4B18 80283C98 C6200004 */  lwc1      $f0, 4($s1)
/* 7E4B1C 80283C9C 4600008D */  trunc.w.s $f2, $f0
/* 7E4B20 80283CA0 44061000 */  mfc1      $a2, $f2
/* 7E4B24 80283CA4 0C0B2026 */  jal       evt_set_variable
/* 7E4B28 80283CA8 0240202D */   daddu    $a0, $s2, $zero
/* 7E4B2C 80283CAC 8E050000 */  lw        $a1, ($s0)
/* 7E4B30 80283CB0 26100004 */  addiu     $s0, $s0, 4
/* 7E4B34 80283CB4 C6200008 */  lwc1      $f0, 8($s1)
/* 7E4B38 80283CB8 4600008D */  trunc.w.s $f2, $f0
/* 7E4B3C 80283CBC 44061000 */  mfc1      $a2, $f2
/* 7E4B40 80283CC0 0C0B2026 */  jal       evt_set_variable
/* 7E4B44 80283CC4 0240202D */   daddu    $a0, $s2, $zero
/* 7E4B48 80283CC8 C620000C */  lwc1      $f0, 0xc($s1)
/* 7E4B4C 80283CCC 8E050000 */  lw        $a1, ($s0)
/* 7E4B50 80283CD0 4600008D */  trunc.w.s $f2, $f0
/* 7E4B54 80283CD4 44061000 */  mfc1      $a2, $f2
/* 7E4B58 80283CD8 0C0B2026 */  jal       evt_set_variable
/* 7E4B5C 80283CDC 0240202D */   daddu    $a0, $s2, $zero
/* 7E4B60 80283CE0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7E4B64 80283CE4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7E4B68 80283CE8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E4B6C 80283CEC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E4B70 80283CF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E4B74 80283CF4 24020002 */  addiu     $v0, $zero, 2
/* 7E4B78 80283CF8 03E00008 */  jr        $ra
/* 7E4B7C 80283CFC 27BD0028 */   addiu    $sp, $sp, 0x28
