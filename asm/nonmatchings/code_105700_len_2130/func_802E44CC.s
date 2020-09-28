.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E44CC
/* 105D4C 802E44CC 0080282D */  daddu     $a1, $a0, $zero
/* 105D50 802E44D0 8CA20028 */  lw        $v0, 0x28($a1)
/* 105D54 802E44D4 14400003 */  bnez      $v0, .L802E44E4
/* 105D58 802E44D8 24020001 */   addiu    $v0, $zero, 1
/* 105D5C 802E44DC 03E00008 */  jr        $ra
/* 105D60 802E44E0 0000102D */   daddu    $v0, $zero, $zero
.L802E44E4:
/* 105D64 802E44E4 8CA30000 */  lw        $v1, ($a1)
/* 105D68 802E44E8 3C040100 */  lui       $a0, 0x100
/* 105D6C 802E44EC 00641825 */  or        $v1, $v1, $a0
/* 105D70 802E44F0 03E00008 */  jr        $ra
/* 105D74 802E44F4 ACA30000 */   sw       $v1, ($a1)
