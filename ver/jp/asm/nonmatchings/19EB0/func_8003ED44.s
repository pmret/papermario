.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003ED44
/* 1A144 8003ED44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A148 8003ED48 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A14C 8003ED4C 0C00E9EB */  jal       func_8003A7AC
/* 1A150 8003ED50 2404FFF6 */   addiu    $a0, $zero, -0xa
/* 1A154 8003ED54 0040182D */  daddu     $v1, $v0, $zero
/* 1A158 8003ED58 906200AC */  lbu       $v0, 0xac($v1)
/* 1A15C 8003ED5C 2442FFEF */  addiu     $v0, $v0, -0x11
/* 1A160 8003ED60 A06200AC */  sb        $v0, 0xac($v1)
/* 1A164 8003ED64 304200FF */  andi      $v0, $v0, 0xff
/* 1A168 8003ED68 14400003 */  bnez      $v0, .L8003ED78
/* 1A16C 8003ED6C 0000102D */   daddu    $v0, $zero, $zero
/* 1A170 8003ED70 A06000AC */  sb        $zero, 0xac($v1)
/* 1A174 8003ED74 24020001 */  addiu     $v0, $zero, 1
.L8003ED78:
/* 1A178 8003ED78 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A17C 8003ED7C 03E00008 */  jr        $ra
/* 1A180 8003ED80 27BD0018 */   addiu    $sp, $sp, 0x18
