.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AE8_EA33E8
/* EA33E8 80242AE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA33EC 80242AEC AFB10014 */  sw        $s1, 0x14($sp)
/* EA33F0 80242AF0 0080882D */  daddu     $s1, $a0, $zero
/* EA33F4 80242AF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA33F8 80242AF8 AFB00010 */  sw        $s0, 0x10($sp)
/* EA33FC 80242AFC 8E30000C */  lw        $s0, 0xc($s1)
/* EA3400 80242B00 8E050000 */  lw        $a1, ($s0)
/* EA3404 80242B04 0C0B53A3 */  jal       func_802D4E8C
/* EA3408 80242B08 26100004 */   addiu    $s0, $s0, 4
/* EA340C 80242B0C AE22008C */  sw        $v0, 0x8c($s1)
/* EA3410 80242B10 8E050000 */  lw        $a1, ($s0)
/* EA3414 80242B14 26100004 */  addiu     $s0, $s0, 4
/* EA3418 80242B18 0C0B53A3 */  jal       func_802D4E8C
/* EA341C 80242B1C 0220202D */   daddu    $a0, $s1, $zero
/* EA3420 80242B20 AE220090 */  sw        $v0, 0x90($s1)
/* EA3424 80242B24 8E050000 */  lw        $a1, ($s0)
/* EA3428 80242B28 26100004 */  addiu     $s0, $s0, 4
/* EA342C 80242B2C 0C0B53A3 */  jal       func_802D4E8C
/* EA3430 80242B30 0220202D */   daddu    $a0, $s1, $zero
/* EA3434 80242B34 AE220094 */  sw        $v0, 0x94($s1)
/* EA3438 80242B38 8E050000 */  lw        $a1, ($s0)
/* EA343C 80242B3C 26100004 */  addiu     $s0, $s0, 4
/* EA3440 80242B40 0C0B53A3 */  jal       func_802D4E8C
/* EA3444 80242B44 0220202D */   daddu    $a0, $s1, $zero
/* EA3448 80242B48 AE220098 */  sw        $v0, 0x98($s1)
/* EA344C 80242B4C 8E050000 */  lw        $a1, ($s0)
/* EA3450 80242B50 26100004 */  addiu     $s0, $s0, 4
/* EA3454 80242B54 0C0B53A3 */  jal       func_802D4E8C
/* EA3458 80242B58 0220202D */   daddu    $a0, $s1, $zero
/* EA345C 80242B5C AE22009C */  sw        $v0, 0x9c($s1)
/* EA3460 80242B60 8E050000 */  lw        $a1, ($s0)
/* EA3464 80242B64 26100004 */  addiu     $s0, $s0, 4
/* EA3468 80242B68 0C0B53A3 */  jal       func_802D4E8C
/* EA346C 80242B6C 0220202D */   daddu    $a0, $s1, $zero
/* EA3470 80242B70 AE2200A0 */  sw        $v0, 0xa0($s1)
/* EA3474 80242B74 8E050000 */  lw        $a1, ($s0)
/* EA3478 80242B78 26100004 */  addiu     $s0, $s0, 4
/* EA347C 80242B7C 0C0B53A3 */  jal       func_802D4E8C
/* EA3480 80242B80 0220202D */   daddu    $a0, $s1, $zero
/* EA3484 80242B84 AE2200A4 */  sw        $v0, 0xa4($s1)
/* EA3488 80242B88 8E050000 */  lw        $a1, ($s0)
/* EA348C 80242B8C 26100004 */  addiu     $s0, $s0, 4
/* EA3490 80242B90 0C0B53A3 */  jal       func_802D4E8C
/* EA3494 80242B94 0220202D */   daddu    $a0, $s1, $zero
/* EA3498 80242B98 AE2200A8 */  sw        $v0, 0xa8($s1)
/* EA349C 80242B9C 8E050000 */  lw        $a1, ($s0)
/* EA34A0 80242BA0 26100004 */  addiu     $s0, $s0, 4
/* EA34A4 80242BA4 0C0B53A3 */  jal       func_802D4E8C
/* EA34A8 80242BA8 0220202D */   daddu    $a0, $s1, $zero
/* EA34AC 80242BAC AE2200AC */  sw        $v0, 0xac($s1)
/* EA34B0 80242BB0 8E050000 */  lw        $a1, ($s0)
/* EA34B4 80242BB4 0C0B53A3 */  jal       func_802D4E8C
/* EA34B8 80242BB8 0220202D */   daddu    $a0, $s1, $zero
/* EA34BC 80242BBC AE2200B0 */  sw        $v0, 0xb0($s1)
/* EA34C0 80242BC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA34C4 80242BC4 8FB10014 */  lw        $s1, 0x14($sp)
/* EA34C8 80242BC8 8FB00010 */  lw        $s0, 0x10($sp)
/* EA34CC 80242BCC 24020002 */  addiu     $v0, $zero, 2
/* EA34D0 80242BD0 03E00008 */  jr        $ra
/* EA34D4 80242BD4 27BD0020 */   addiu    $sp, $sp, 0x20
