.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFA58_3207C8
/* 3207C8 802BFA58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3207CC 802BFA5C 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 3207D0 802BFA60 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 3207D4 802BFA64 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3207D8 802BFA68 80620001 */  lb        $v0, 1($v1)
/* 3207DC 802BFA6C 1040000F */  beqz      $v0, .L802BFAAC
/* 3207E0 802BFA70 24620018 */   addiu    $v0, $v1, 0x18
/* 3207E4 802BFA74 24630358 */  addiu     $v1, $v1, 0x358
.L802BFA78:
/* 3207E8 802BFA78 8C450000 */  lw        $a1, ($v0)
/* 3207EC 802BFA7C 8C460004 */  lw        $a2, 4($v0)
/* 3207F0 802BFA80 8C470008 */  lw        $a3, 8($v0)
/* 3207F4 802BFA84 8C48000C */  lw        $t0, 0xc($v0)
/* 3207F8 802BFA88 AC850000 */  sw        $a1, ($a0)
/* 3207FC 802BFA8C AC860004 */  sw        $a2, 4($a0)
/* 320800 802BFA90 AC870008 */  sw        $a3, 8($a0)
/* 320804 802BFA94 AC88000C */  sw        $t0, 0xc($a0)
/* 320808 802BFA98 24420010 */  addiu     $v0, $v0, 0x10
/* 32080C 802BFA9C 1443FFF6 */  bne       $v0, $v1, .L802BFA78
/* 320810 802BFAA0 24840010 */   addiu    $a0, $a0, 0x10
/* 320814 802BFAA4 0C03ACC5 */  jal       partner_use_ability
/* 320818 802BFAA8 00000000 */   nop
.L802BFAAC:
/* 32081C 802BFAAC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 320820 802BFAB0 03E00008 */  jr        $ra
/* 320824 802BFAB4 27BD0018 */   addiu    $sp, $sp, 0x18
