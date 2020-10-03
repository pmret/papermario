.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E4484
/* 105D04 802E4484 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 105D08 802E4488 0080182D */  daddu     $v1, $a0, $zero
/* 105D0C 802E448C 2405FEFF */  addiu     $a1, $zero, -0x101
/* 105D10 802E4490 AFBF0010 */  sw        $ra, 0x10($sp)
/* 105D14 802E4494 8C620000 */  lw        $v0, ($v1)
/* 105D18 802E4498 84640016 */  lh        $a0, 0x16($v1)
/* 105D1C 802E449C 34420001 */  ori       $v0, $v0, 1
/* 105D20 802E44A0 00451024 */  and       $v0, $v0, $a1
/* 105D24 802E44A4 0C044181 */  jal       get_shadow_by_index
/* 105D28 802E44A8 AC620000 */   sw       $v0, ($v1)
/* 105D2C 802E44AC 3C041000 */  lui       $a0, 0x1000
/* 105D30 802E44B0 8C430000 */  lw        $v1, ($v0)
/* 105D34 802E44B4 34840001 */  ori       $a0, $a0, 1
/* 105D38 802E44B8 00641825 */  or        $v1, $v1, $a0
/* 105D3C 802E44BC AC430000 */  sw        $v1, ($v0)
/* 105D40 802E44C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 105D44 802E44C4 03E00008 */  jr        $ra
/* 105D48 802E44C8 27BD0018 */   addiu    $sp, $sp, 0x18
