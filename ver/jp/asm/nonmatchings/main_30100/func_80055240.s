.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055240
/* 30640 80055240 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30644 80055244 AFB10014 */  sw        $s1, 0x14($sp)
/* 30648 80055248 0080882D */  daddu     $s1, $a0, $zero
/* 3064C 8005524C AFB20018 */  sw        $s2, 0x18($sp)
/* 30650 80055250 00A0902D */  daddu     $s2, $a1, $zero
/* 30654 80055254 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30658 80055258 0C014238 */  jal       func_800508E0
/* 3065C 8005525C AFB00010 */   sw       $s0, 0x10($sp)
/* 30660 80055260 0040802D */  daddu     $s0, $v0, $zero
/* 30664 80055264 16000005 */  bnez      $s0, .L8005527C
/* 30668 80055268 0200102D */   daddu    $v0, $s0, $zero
/* 3066C 8005526C 0220202D */  daddu     $a0, $s1, $zero
/* 30670 80055270 0C0142CD */  jal       func_80050B34
/* 30674 80055274 0240282D */   daddu    $a1, $s2, $zero
/* 30678 80055278 0200102D */  daddu     $v0, $s0, $zero
.L8005527C:
/* 3067C 8005527C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 30680 80055280 8FB20018 */  lw        $s2, 0x18($sp)
/* 30684 80055284 8FB10014 */  lw        $s1, 0x14($sp)
/* 30688 80055288 8FB00010 */  lw        $s0, 0x10($sp)
/* 3068C 8005528C 03E00008 */  jr        $ra
/* 30690 80055290 27BD0020 */   addiu    $sp, $sp, 0x20
