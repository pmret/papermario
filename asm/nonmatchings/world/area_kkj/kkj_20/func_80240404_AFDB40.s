.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_AFDF44
/* AFDF44 80240404 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AFDF48 80240408 AFBF0010 */  sw        $ra, 0x10($sp)
/* AFDF4C 8024040C 8C82000C */  lw        $v0, 0xc($a0)
/* AFDF50 80240410 0C0B1EAF */  jal       get_variable
/* AFDF54 80240414 8C450000 */   lw       $a1, ($v0)
/* AFDF58 80240418 0C0B1059 */  jal       does_script_exist
/* AFDF5C 8024041C 0040202D */   daddu    $a0, $v0, $zero
/* AFDF60 80240420 2C420001 */  sltiu     $v0, $v0, 1
/* AFDF64 80240424 8FBF0010 */  lw        $ra, 0x10($sp)
/* AFDF68 80240428 00021040 */  sll       $v0, $v0, 1
/* AFDF6C 8024042C 03E00008 */  jr        $ra
/* AFDF70 80240430 27BD0018 */   addiu    $sp, $sp, 0x18
