.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802431B4_8B3224
/* 8B3224 802431B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B3228 802431B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B322C 802431BC 8C82000C */  lw        $v0, 0xc($a0)
/* 8B3230 802431C0 0C0B1EAF */  jal       get_variable
/* 8B3234 802431C4 8C450000 */   lw       $a1, ($v0)
/* 8B3238 802431C8 0C0B1059 */  jal       does_script_exist
/* 8B323C 802431CC 0040202D */   daddu    $a0, $v0, $zero
/* 8B3240 802431D0 2C420001 */  sltiu     $v0, $v0, 1
/* 8B3244 802431D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B3248 802431D8 00021040 */  sll       $v0, $v0, 1
/* 8B324C 802431DC 03E00008 */  jr        $ra
/* 8B3250 802431E0 27BD0018 */   addiu    $sp, $sp, 0x18
