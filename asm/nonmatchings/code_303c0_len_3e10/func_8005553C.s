.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005553C
/* 3093C 8005553C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30940 80055540 AFB10014 */  sw        $s1, 0x14($sp)
/* 30944 80055544 0080882D */  daddu     $s1, $a0, $zero
/* 30948 80055548 AFB20018 */  sw        $s2, 0x18($sp)
/* 3094C 8005554C 00A0902D */  daddu     $s2, $a1, $zero
/* 30950 80055550 AFBF001C */  sw        $ra, 0x1c($sp)
/* 30954 80055554 0C01430C */  jal       func_80050C30
/* 30958 80055558 AFB00010 */   sw       $s0, 0x10($sp)
/* 3095C 8005555C 0040802D */  daddu     $s0, $v0, $zero
/* 30960 80055560 16000005 */  bnez      $s0, .L80055578
/* 30964 80055564 0200102D */   daddu    $v0, $s0, $zero
/* 30968 80055568 0220202D */  daddu     $a0, $s1, $zero
/* 3096C 8005556C 0C014386 */  jal       func_80050E18
/* 30970 80055570 0240282D */   daddu    $a1, $s2, $zero
/* 30974 80055574 0200102D */  daddu     $v0, $s0, $zero
.L80055578:
/* 30978 80055578 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3097C 8005557C 8FB20018 */  lw        $s2, 0x18($sp)
/* 30980 80055580 8FB10014 */  lw        $s1, 0x14($sp)
/* 30984 80055584 8FB00010 */  lw        $s0, 0x10($sp)
/* 30988 80055588 03E00008 */  jr        $ra
/* 3098C 8005558C 27BD0020 */   addiu    $sp, $sp, 0x20
