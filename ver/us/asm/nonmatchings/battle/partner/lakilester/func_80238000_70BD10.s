.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238000_70BD10
/* 70BD10 80238000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 70BD14 80238004 10A00003 */  beqz      $a1, .L80238014
/* 70BD18 80238008 AFBF0010 */   sw       $ra, 0x10($sp)
/* 70BD1C 8023800C 3C018024 */  lui       $at, %hi(D_8023D2C8)
/* 70BD20 80238010 AC20D2C8 */  sw        $zero, %lo(D_8023D2C8)($at)
.L80238014:
/* 70BD24 80238014 3C028024 */  lui       $v0, %hi(D_8023D2C8)
/* 70BD28 80238018 8C42D2C8 */  lw        $v0, %lo(D_8023D2C8)($v0)
/* 70BD2C 8023801C 14400004 */  bnez      $v0, .L80238030
/* 70BD30 80238020 24020002 */   addiu    $v0, $zero, 2
/* 70BD34 80238024 0C093EB1 */  jal       btl_set_popup_duration
/* 70BD38 80238028 24040063 */   addiu    $a0, $zero, 0x63
/* 70BD3C 8023802C 0000102D */  daddu     $v0, $zero, $zero
.L80238030:
/* 70BD40 80238030 8FBF0010 */  lw        $ra, 0x10($sp)
/* 70BD44 80238034 03E00008 */  jr        $ra
/* 70BD48 80238038 27BD0018 */   addiu    $sp, $sp, 0x18
