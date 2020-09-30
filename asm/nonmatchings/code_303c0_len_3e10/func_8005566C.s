.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005566C
/* 30A6C 8005566C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 30A70 80055670 AFB10014 */  sw        $s1, 0x14($sp)
/* 30A74 80055674 0080882D */  daddu     $s1, $a0, $zero
/* 30A78 80055678 AFB20018 */  sw        $s2, 0x18($sp)
/* 30A7C 8005567C 00A0902D */  daddu     $s2, $a1, $zero
/* 30A80 80055680 AFB3001C */  sw        $s3, 0x1c($sp)
/* 30A84 80055684 00C0982D */  daddu     $s3, $a2, $zero
/* 30A88 80055688 AFBF0020 */  sw        $ra, 0x20($sp)
/* 30A8C 8005568C 0C01430C */  jal       func_80050C30
/* 30A90 80055690 AFB00010 */   sw       $s0, 0x10($sp)
/* 30A94 80055694 0040802D */  daddu     $s0, $v0, $zero
/* 30A98 80055698 16000006 */  bnez      $s0, .L800556B4
/* 30A9C 8005569C 0200102D */   daddu    $v0, $s0, $zero
/* 30AA0 800556A0 0220202D */  daddu     $a0, $s1, $zero
/* 30AA4 800556A4 0240282D */  daddu     $a1, $s2, $zero
/* 30AA8 800556A8 0C0143F4 */  jal       func_80050FD0
/* 30AAC 800556AC 0260302D */   daddu    $a2, $s3, $zero
/* 30AB0 800556B0 0200102D */  daddu     $v0, $s0, $zero
.L800556B4:
/* 30AB4 800556B4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 30AB8 800556B8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 30ABC 800556BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 30AC0 800556C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 30AC4 800556C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 30AC8 800556C8 03E00008 */  jr        $ra
/* 30ACC 800556CC 27BD0028 */   addiu    $sp, $sp, 0x28
