.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_128_update
/* 406C3C E011C0FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 406C40 E011C100 AFBF0010 */  sw        $ra, 0x10($sp)
/* 406C44 E011C104 8C850000 */  lw        $a1, ($a0)
/* 406C48 E011C108 8C83000C */  lw        $v1, 0xc($a0)
/* 406C4C E011C10C 30A20010 */  andi      $v0, $a1, 0x10
/* 406C50 E011C110 10400005 */  beqz      $v0, .LE011C128
/* 406C54 E011C114 2402FFEF */   addiu    $v0, $zero, -0x11
/* 406C58 E011C118 00A21024 */  and       $v0, $a1, $v0
/* 406C5C E011C11C AC820000 */  sw        $v0, ($a0)
/* 406C60 E011C120 24020010 */  addiu     $v0, $zero, 0x10
/* 406C64 E011C124 AC620010 */  sw        $v0, 0x10($v1)
.LE011C128:
/* 406C68 E011C128 8C650010 */  lw        $a1, 0x10($v1)
/* 406C6C E011C12C 28A203E8 */  slti      $v0, $a1, 0x3e8
/* 406C70 E011C130 10400002 */  beqz      $v0, .LE011C13C
/* 406C74 E011C134 24A2FFFF */   addiu    $v0, $a1, -1
/* 406C78 E011C138 AC620010 */  sw        $v0, 0x10($v1)
.LE011C13C:
/* 406C7C E011C13C 8C620014 */  lw        $v0, 0x14($v1)
/* 406C80 E011C140 8C650010 */  lw        $a1, 0x10($v1)
/* 406C84 E011C144 24420001 */  addiu     $v0, $v0, 1
/* 406C88 E011C148 04A10005 */  bgez      $a1, .LE011C160
/* 406C8C E011C14C AC620014 */   sw       $v0, 0x14($v1)
/* 406C90 E011C150 0C080128 */  jal       shim_remove_effect
/* 406C94 E011C154 00000000 */   nop
/* 406C98 E011C158 0804705C */  j         .LE011C170
/* 406C9C E011C15C 00000000 */   nop
.LE011C160:
/* 406CA0 E011C160 28A20010 */  slti      $v0, $a1, 0x10
/* 406CA4 E011C164 10400002 */  beqz      $v0, .LE011C170
/* 406CA8 E011C168 00051100 */   sll      $v0, $a1, 4
/* 406CAC E011C16C AC620018 */  sw        $v0, 0x18($v1)
.LE011C170:
/* 406CB0 E011C170 8FBF0010 */  lw        $ra, 0x10($sp)
/* 406CB4 E011C174 03E00008 */  jr        $ra
/* 406CB8 E011C178 27BD0018 */   addiu    $sp, $sp, 0x18
