.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802823B0
/* 7E3230 802823B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E3234 802823B4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E3238 802823B8 0080802D */  daddu     $s0, $a0, $zero
/* 7E323C 802823BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E3240 802823C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E3244 802823C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E3248 802823C8 8E11000C */  lw        $s1, 0xc($s0)
/* 7E324C 802823CC 8E120074 */  lw        $s2, 0x74($s0)
/* 7E3250 802823D0 8E250000 */  lw        $a1, ($s1)
/* 7E3254 802823D4 0C0B1EAF */  jal       get_variable
/* 7E3258 802823D8 26310004 */   addiu    $s1, $s1, 4
/* 7E325C 802823DC 0200202D */  daddu     $a0, $s0, $zero
/* 7E3260 802823E0 8E250000 */  lw        $a1, ($s1)
/* 7E3264 802823E4 0C0B1EAF */  jal       get_variable
/* 7E3268 802823E8 0040802D */   daddu    $s0, $v0, $zero
/* 7E326C 802823EC 00108080 */  sll       $s0, $s0, 2
/* 7E3270 802823F0 02509021 */  addu      $s2, $s2, $s0
/* 7E3274 802823F4 AE42004C */  sw        $v0, 0x4c($s2)
/* 7E3278 802823F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E327C 802823FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E3280 80282400 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E3284 80282404 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E3288 80282408 24020002 */  addiu     $v0, $zero, 2
/* 7E328C 8028240C 03E00008 */  jr        $ra
/* 7E3290 80282410 27BD0020 */   addiu    $sp, $sp, 0x20
