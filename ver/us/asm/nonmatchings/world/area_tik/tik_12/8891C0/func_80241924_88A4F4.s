.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241924_88A4F4
/* 88A4F4 80241924 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* 88A4F8 80241928 2463EBB0 */  addiu     $v1, $v1, %lo(D_8010EBB0)
/* 88A4FC 8024192C AC800084 */  sw        $zero, 0x84($a0)
/* 88A500 80241930 80620000 */  lb        $v0, ($v1)
/* 88A504 80241934 10400005 */  beqz      $v0, .L8024194C
/* 88A508 80241938 24020003 */   addiu    $v0, $zero, 3
/* 88A50C 8024193C 80630003 */  lb        $v1, 3($v1)
/* 88A510 80241940 14620002 */  bne       $v1, $v0, .L8024194C
/* 88A514 80241944 24020001 */   addiu    $v0, $zero, 1
/* 88A518 80241948 AC820084 */  sw        $v0, 0x84($a0)
.L8024194C:
/* 88A51C 8024194C 03E00008 */  jr        $ra
/* 88A520 80241950 24020002 */   addiu    $v0, $zero, 2
/* 88A524 80241954 00000000 */  nop
/* 88A528 80241958 00000000 */  nop
/* 88A52C 8024195C 00000000 */  nop
