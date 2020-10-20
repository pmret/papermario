.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024166C
/* A880BC 8024166C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A880C0 80241670 AFBF0010 */  sw        $ra, 0x10($sp)
/* A880C4 80241674 8C82000C */  lw        $v0, 0xc($a0)
/* A880C8 80241678 0C0B1EAF */  jal       get_variable
/* A880CC 8024167C 8C450000 */   lw       $a1, ($v0)
/* A880D0 80241680 0C0B1059 */  jal       does_script_exist
/* A880D4 80241684 0040202D */   daddu    $a0, $v0, $zero
/* A880D8 80241688 2C420001 */  sltiu     $v0, $v0, 1
/* A880DC 8024168C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A880E0 80241690 00021040 */  sll       $v0, $v0, 1
/* A880E4 80241694 03E00008 */  jr        $ra
/* A880E8 80241698 27BD0018 */   addiu    $sp, $sp, 0x18
