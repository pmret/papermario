.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055C84
/* 31084 80055C84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31088 80055C88 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3108C 80055C8C 0C015702 */  jal       func_80055C08
/* 31090 80055C90 0000302D */   daddu    $a2, $zero, $zero
/* 31094 80055C94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31098 80055C98 03E00008 */  jr        $ra
/* 3109C 80055C9C 27BD0018 */   addiu    $sp, $sp, 0x18
