.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003823C
/* 1363C 8003823C 0000182D */  daddu     $v1, $zero, $zero
/* 13640 80038240 24630001 */  addiu     $v1, $v1, 1
.L80038244:
/* 13644 80038244 28620040 */  slti      $v0, $v1, 0x40
/* 13648 80038248 1440FFFE */  bnez      $v0, .L80038244
/* 1364C 8003824C 24630001 */   addiu    $v1, $v1, 1
/* 13650 80038250 03E00008 */  jr        $ra
/* 13654 80038254 00000000 */   nop
