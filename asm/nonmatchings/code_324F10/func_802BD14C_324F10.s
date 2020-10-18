.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD14C_324F10
/* 324F5C 802BD14C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 324F60 802BD150 AFB10014 */  sw        $s1, 0x14($sp)
/* 324F64 802BD154 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 324F68 802BD158 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 324F6C 802BD15C AFBF0018 */  sw        $ra, 0x18($sp)
/* 324F70 802BD160 AFB00010 */  sw        $s0, 0x10($sp)
/* 324F74 802BD164 8C90014C */  lw        $s0, 0x14c($a0)
/* 324F78 802BD168 10A00003 */  beqz      $a1, .L802BD178
/* 324F7C 802BD16C 0200202D */   daddu    $a0, $s0, $zero
/* 324F80 802BD170 0C03AE2A */  jal       enable_partner_walking
/* 324F84 802BD174 24050001 */   addiu    $a1, $zero, 1
.L802BD178:
/* 324F88 802BD178 0C03AE8F */  jal       func_800EBA3C
/* 324F8C 802BD17C 0200202D */   daddu    $a0, $s0, $zero
/* 324F90 802BD180 0C03AED0 */  jal       func_800EBB40
/* 324F94 802BD184 0200202D */   daddu    $a0, $s0, $zero
/* 324F98 802BD188 8E22031C */  lw        $v0, 0x31c($s1)
/* 324F9C 802BD18C 24420001 */  addiu     $v0, $v0, 1
/* 324FA0 802BD190 AE22031C */  sw        $v0, 0x31c($s1)
/* 324FA4 802BD194 8FBF0018 */  lw        $ra, 0x18($sp)
/* 324FA8 802BD198 8FB10014 */  lw        $s1, 0x14($sp)
/* 324FAC 802BD19C 8FB00010 */  lw        $s0, 0x10($sp)
/* 324FB0 802BD1A0 0000102D */  daddu     $v0, $zero, $zero
/* 324FB4 802BD1A4 03E00008 */  jr        $ra
/* 324FB8 802BD1A8 27BD0020 */   addiu    $sp, $sp, 0x20
