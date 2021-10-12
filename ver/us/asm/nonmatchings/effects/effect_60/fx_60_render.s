.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_60_render
/* 37A600 E0078210 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 37A604 E0078214 AFBF0020 */  sw        $ra, 0x20($sp)
/* 37A608 E0078218 8C83000C */  lw        $v1, 0xc($a0)
/* 37A60C E007821C 3C02E008 */  lui       $v0, %hi(func_E007827C)
/* 37A610 E0078220 2442827C */  addiu     $v0, $v0, %lo(func_E007827C)
/* 37A614 E0078224 AFA40018 */  sw        $a0, 0x18($sp)
/* 37A618 E0078228 AFA2001C */  sw        $v0, 0x1c($sp)
/* 37A61C E007822C 8C630000 */  lw        $v1, ($v1)
/* 37A620 E0078230 24020005 */  addiu     $v0, $zero, 5
/* 37A624 E0078234 14620004 */  bne       $v1, $v0, .LE0078248
/* 37A628 E0078238 27A40010 */   addiu    $a0, $sp, 0x10
/* 37A62C E007823C 24020001 */  addiu     $v0, $zero, 1
/* 37A630 E0078240 0801E095 */  j         .LE0078254
/* 37A634 E0078244 AFA00014 */   sw       $zero, 0x14($sp)
.LE0078248:
/* 37A638 E0078248 2402FF9C */  addiu     $v0, $zero, -0x64
/* 37A63C E007824C AFA20014 */  sw        $v0, 0x14($sp)
/* 37A640 E0078250 2402002D */  addiu     $v0, $zero, 0x2d
.LE0078254:
/* 37A644 E0078254 0C080120 */  jal       shim_queue_render_task
/* 37A648 E0078258 AFA20010 */   sw       $v0, 0x10($sp)
/* 37A64C E007825C 8C430000 */  lw        $v1, ($v0)
/* 37A650 E0078260 34630002 */  ori       $v1, $v1, 2
/* 37A654 E0078264 AC430000 */  sw        $v1, ($v0)
/* 37A658 E0078268 8FBF0020 */  lw        $ra, 0x20($sp)
/* 37A65C E007826C 03E00008 */  jr        $ra
/* 37A660 E0078270 27BD0028 */   addiu    $sp, $sp, 0x28
