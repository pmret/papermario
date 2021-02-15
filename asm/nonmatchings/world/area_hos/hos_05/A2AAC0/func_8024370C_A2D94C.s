.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024370C_A2D94C
/* A2D94C 8024370C 3C038025 */  lui       $v1, %hi(D_8024AA20_A34C60)
/* A2D950 80243710 8C63AA20 */  lw        $v1, %lo(D_8024AA20_A34C60)($v1)
/* A2D954 80243714 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2D958 80243718 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2D95C 8024371C 84640048 */  lh        $a0, 0x48($v1)
/* A2D960 80243720 8465004A */  lh        $a1, 0x4a($v1)
/* A2D964 80243724 8466005C */  lh        $a2, 0x5c($v1)
/* A2D968 80243728 24020080 */  addiu     $v0, $zero, 0x80
/* A2D96C 8024372C AFA20014 */  sw        $v0, 0x14($sp)
/* A2D970 80243730 AFA20018 */  sw        $v0, 0x18($sp)
/* A2D974 80243734 24020020 */  addiu     $v0, $zero, 0x20
/* A2D978 80243738 AFA2001C */  sw        $v0, 0x1c($sp)
/* A2D97C 8024373C AFA60010 */  sw        $a2, 0x10($sp)
/* A2D980 80243740 8C660018 */  lw        $a2, 0x18($v1)
/* A2D984 80243744 0C090C59 */  jal       func_80243164_A2D3A4
/* A2D988 80243748 0000382D */   daddu    $a3, $zero, $zero
/* A2D98C 8024374C 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2D990 80243750 03E00008 */  jr        $ra
/* A2D994 80243754 27BD0028 */   addiu    $sp, $sp, 0x28
