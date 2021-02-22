.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80072CD4
/* 4E0D4 80072CD4 3C013F80 */  lui       $at, 0x3f80
/* 4E0D8 80072CD8 44816000 */  mtc1      $at, $f12
/* 4E0DC 80072CDC 3C013F8C */  lui       $at, 0x3f8c
/* 4E0E0 80072CE0 3421CCCD */  ori       $at, $at, 0xcccd
/* 4E0E4 80072CE4 44817000 */  mtc1      $at, $f14
/* 4E0E8 80072CE8 3C063F99 */  lui       $a2, 0x3f99
/* 4E0EC 80072CEC 34C6999A */  ori       $a2, $a2, 0x999a
/* 4E0F0 80072CF0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E0F4 80072CF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E0F8 80072CF8 0C01CB33 */  jal       func_80072CCC
/* 4E0FC 80072CFC 00000000 */   nop
/* 4E100 80072D00 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E104 80072D04 03E00008 */  jr        $ra
/* 4E108 80072D08 27BD0018 */   addiu    $sp, $sp, 0x18
