.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B24_BBDCC4
/* BBDCC4 80240B24 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBDCC8 80240B28 AFBF0010 */  sw        $ra, 0x10($sp)
/* BBDCCC 80240B2C 10A00003 */  beqz      $a1, .L80240B3C
/* BBDCD0 80240B30 8C86000C */   lw       $a2, 0xc($a0)
/* BBDCD4 80240B34 3C018024 */  lui       $at, %hi(D_80244154_BC12F4)
/* BBDCD8 80240B38 AC204154 */  sw        $zero, %lo(D_80244154_BC12F4)($at)
.L80240B3C:
/* BBDCDC 80240B3C 3C038024 */  lui       $v1, %hi(D_80244154_BC12F4)
/* BBDCE0 80240B40 24634154 */  addiu     $v1, $v1, %lo(D_80244154_BC12F4)
/* BBDCE4 80240B44 8C620000 */  lw        $v0, ($v1)
/* BBDCE8 80240B48 54400003 */  bnel      $v0, $zero, .L80240B58
/* BBDCEC 80240B4C AC600000 */   sw       $zero, ($v1)
/* BBDCF0 80240B50 080902DB */  j         .L80240B6C
/* BBDCF4 80240B54 0000102D */   daddu    $v0, $zero, $zero
.L80240B58:
/* BBDCF8 80240B58 8CC50000 */  lw        $a1, ($a2)
/* BBDCFC 80240B5C 3C068024 */  lui       $a2, %hi(D_80244158_BC12F8)
/* BBDD00 80240B60 0C0B2026 */  jal       evt_set_variable
/* BBDD04 80240B64 8CC64158 */   lw       $a2, %lo(D_80244158_BC12F8)($a2)
/* BBDD08 80240B68 24020002 */  addiu     $v0, $zero, 2
.L80240B6C:
/* BBDD0C 80240B6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBDD10 80240B70 03E00008 */  jr        $ra
/* BBDD14 80240B74 27BD0018 */   addiu    $sp, $sp, 0x18
