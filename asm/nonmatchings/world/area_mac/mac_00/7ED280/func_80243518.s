.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243518
/* 7EE228 80243518 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EE22C 8024351C AFB10014 */  sw        $s1, 0x14($sp)
/* 7EE230 80243520 0080882D */  daddu     $s1, $a0, $zero
/* 7EE234 80243524 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EE238 80243528 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE23C 8024352C 8E30000C */  lw        $s0, 0xc($s1)
/* 7EE240 80243530 8E050000 */  lw        $a1, ($s0)
/* 7EE244 80243534 0C0B1EAF */  jal       get_variable
/* 7EE248 80243538 26100004 */   addiu    $s0, $s0, 4
/* 7EE24C 8024353C 0C00EAD2 */  jal       get_npc_safe
/* 7EE250 80243540 0040202D */   daddu    $a0, $v0, $zero
/* 7EE254 80243544 10400005 */  beqz      $v0, .L8024355C
/* 7EE258 80243548 00000000 */   nop      
/* 7EE25C 8024354C 8E050000 */  lw        $a1, ($s0)
/* 7EE260 80243550 844600A8 */  lh        $a2, 0xa8($v0)
/* 7EE264 80243554 0C0B2026 */  jal       set_variable
/* 7EE268 80243558 0220202D */   daddu    $a0, $s1, $zero
.L8024355C:
/* 7EE26C 8024355C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EE270 80243560 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EE274 80243564 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE278 80243568 24020002 */  addiu     $v0, $zero, 2
/* 7EE27C 8024356C 03E00008 */  jr        $ra
/* 7EE280 80243570 27BD0020 */   addiu    $sp, $sp, 0x20
